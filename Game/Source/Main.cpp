#include "Engine.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
#include <cassert>

int main(int argc, char* argv[])
{

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initalize();

	File::SetFilePath("Assets");

	std::cout << File::GetFilePath() << endl;

	{
		// create texture, using shared_ptr so texture can be shared
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("monty.jpg", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ka1.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });

		Transform t{ {30,30} };
		std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
		std::unique_ptr<TextureComponent> textureComp = std::make_unique<TextureComponent>();
		textureComp->texture = texture;
		actor->AddComponent(std::move(textureComp));

		while (!engine->IsQuit())
		{
			engine->Update();

			actor->Update(engine->GetTime().GetDeltaTime());

			engine->GetRenderer().SetColor(0, 0, 0, 0);

			engine->GetRenderer().BeginFrame();

			//engine->GetRenderer().DrawTexture(texture.get(), 30, 30);

			actor->Draw(engine->GetRenderer());

			text->Draw(engine->GetRenderer(), 100, 100);

			engine->GetPartSys().Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}
	}

	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}