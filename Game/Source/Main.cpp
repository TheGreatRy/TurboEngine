#include "Engine.h"
#include "CoolGame.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
#include <cassert>

int main(int argc, char* argv[])
{

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << endl;

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initalize();

	std::unique_ptr<CoolGame> game = make_unique<CoolGame>(engine.get());
	game->Initialize();

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
			game->Update(engine->GetTime().GetDeltaTime());
			
			//Renderer
			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();

			//Draw
			game->Draw(engine->GetRenderer());
			engine->GetRenderer().EndFrame();
		}
	}

	game->Shutdown();
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}