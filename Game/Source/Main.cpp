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

	while (!engine->IsQuit()) 
	{
		engine->Update();
		
		engine->GetRenderer().SetColor(0, 0, 0, 0);
		
		engine->GetRenderer().BeginFrame();

		engine->GetPartSys().Draw(engine->GetRenderer());

		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();
	return 0;
}