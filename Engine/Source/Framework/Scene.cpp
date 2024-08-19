#include "Scene.h"
#include "Actor.h"
#include "Core/Factory.h"
#include "Components/CollisionComponent.h"
#include <algorithm>

void Scene::Read(const json_t& value)
{
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray())
	{
		for (auto& actorVal : GET_DATA(value, actors).GetArray())
		{
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
			actor->Read(actorVal);

			AddActor(std::move(actor));
		}
	}
}

void Scene::Write(json_t& value)
{
}

void Scene::Initialize()
{
	for (auto& actor : actors)
	{
		actor->Initialize();
	}
}
void Scene::Update(float dt)
{
	// update
	for (auto& actor : actors)
	{
		if(actor->active) actor->Update(dt);
	}
	//destroy
	std::erase_if(actors, [](auto& actor) {return actor->destroyed;});

	//collision
	for (auto& actor1 : actors)
	{
		CollisionComponent* collision1 = actor1->GetComponent<CollisionComponent>();
		if (!collision1) continue;

		for (auto& actor2 : actors)
		{
			if (actor1 == actor2) continue;

			CollisionComponent* collision2 = actor2->GetComponent<CollisionComponent>();
			if (!collision2) continue;

			if (collision1->CheckCollision(collision2))
			{
				//std::cout << "hit!\n";
				if (actor1->OnCollisionEnter) actor1->OnCollisionEnter(actor2.get());
				if (actor2->OnCollisionEnter) actor2->OnCollisionEnter(actor1.get());
			}
			
		}
	}

}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : actors)
	{
		if(actor->active) actor->Draw(renderer);
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor)
{
	actor->scene = this;
	actors.push_back(std::move(actor));
}

void Scene::RemoveAll()
{
	actors.clear();
}

