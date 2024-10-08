#include "PlayerComponent.h"
#include "Engine.h"

FACTORY_REGISTER(PlayerComponent)

void PlayerComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1);
}
void PlayerComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void PlayerComponent::Write(json_t& value)
{
}


void PlayerComponent::Update(float dt)
{
	float rotate = 0;
	float thrust = 0;
	
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_UP) && owner->scene->engine->GetInput().GetPrevKeyDown(SDL_SCANCODE_UP) )
	{
		owner->scene->GetActor<Actor>("player")->active = false;
		//owner->scene->GetActor<Actor>("enemy")->active = true;

		
		
		auto rocket = Factory::Instance().Create<Actor>("enemy");
		rocket->transform.position = owner->transform.position;
		rocket->transform.rotation = owner->transform.rotation;
		owner->scene->AddActor(std::move(rocket), true);
	}
	else if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D))
	{
		rotate = 1;
	} 
	else if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W))
	{
		thrust = 1;
	}
	else if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S))
	{
		thrust = -1;
	}
	/*owner->GetComponent<PhysicsComponent>()->ApplyTorque(rotate * 90 * dt);
	Vector2 direction = Vector2{ 1,0 }.Rotate(Math::DegToRad(owner->transform.rotation));
	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed * thrust);*/
	
}

void PlayerComponent::OnCollisionEnter(Actor* actor)
{
	//std::cout << "player hit!\n";
	//EVENT_NOTIFY(PlayerDead)
}
