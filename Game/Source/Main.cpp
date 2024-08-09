#include "Engine.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
#include <cassert>

int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initalize();

	File::SetFilePath("Assets");

	
	std::string s;
	File::ReadFile("test.txt", s);
	//std::cout << s;

	rapidjson::Document document;
	Json::Load("test.txt", document);

	std::string name;
	int age;
	bool isAwake;
	float speed;
	Vector2 position;
	Color color;


	READ_DATA(document, name);
	READ_DATA(document, age);
	READ_DATA(document, isAwake);
	READ_DATA(document, speed);
	READ_DATA(document, position);
	READ_DATA(document, color);

	//Json::Read(document, "speed", speed);
	//Json::Read(document, "name", name);
	//Json::Read(document, "age", age);
	//Json::Read(document, "isAwake", isAwake);

	std::cout << "Name: " << name << " Age: " << age << " Awake?: " << isAwake << std::endl;
	std::cout << speed << std::endl;
	std::cout << position.x << " " << position.y << std::endl;
	std::cout << color.r << " " << color.g << " " << color.b << " " << color.a << std::endl;

	std::cout << File::GetFilePath() << endl;

	{
		// create texture, using shared_ptr so texture can be shared
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("monty.jpg", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ka1.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });

		Transform t{ {30,30} };
		std::unique_ptr<Actor> actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
		actor->SetTransform(t);
		std::unique_ptr<TextureComponent> textureComp = Factory::Instance().Create<TextureComponent>(TextureComponent::GetTypeName());
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