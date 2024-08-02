#include "Engine.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
#include <cassert>

int main(int argc, char* argv[]) {

	std::unique_ptr<Engine> engine =  std::make_unique<Engine>();

	engine->Initalize();

	File::SetFilePath("Assets");

	std::cout << File::GetFilePath() << endl;
	// create texture, using shared_ptr so texture can be shared
	std::shared_ptr<Texture> texture = std::make_shared<Texture>();
	texture->Load("monty.jpg", engine->GetRenderer());


	while (!engine->IsQuit()) 
	{
		engine->Update();
		
		engine->GetRenderer().SetColor(0, 0, 0, 0);
		
		engine->GetRenderer().BeginFrame();

		engine->GetRenderer().DrawTexture(texture.get(), 30, 30);


		engine->GetPartSys().Draw(engine->GetRenderer());

		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();
	return 0;
}