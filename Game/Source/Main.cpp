#include "Engine.h"
#include "Components/PlayerComponent.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
#include <cassert>

int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initalize();

	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << endl;

	
	//std::string buffer;
	//File::ReadFile("Scenes/scene.json", buffer);
	//std::cout << buffer << std::endl;

	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	scene->Read(document);
	scene->Initialize();


	{
		// create texture, using shared_ptr so texture can be shared
		/*
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("monty.jpg", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ka1.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });

		Transform t{ {30,30} };
		std::unique_ptr<Actor> actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
		actor->transform = t;
		std::unique_ptr<TextureComponent> textureComp = Factory::Instance().Create<TextureComponent>(TextureComponent::GetTypeName());
		textureComp->texture = texture;
		actor->AddComponent(std::move(textureComp));
		*/

		while (!engine->IsQuit())
		{
			//Update
			engine->Update();
			scene->Update(engine->GetTime().GetDeltaTime());

			auto* actor = scene->GetActor<Actor>("text");
			if (actor)
			{
				actor->Update(engine->GetTime().GetDeltaTime());
			}
			//Renderer
			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();

			//Draw
			scene->Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}
	}

	scene->RemoveAll();
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}