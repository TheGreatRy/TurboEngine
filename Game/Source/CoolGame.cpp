#include "CoolGame.h"
#include "Engine.h"
#include <memory>

bool CoolGame::Initialize()
{
	m_scene = std::make_unique<Scene>(m_engine);
	std::string sceneNames[] = { "Scenes/scene.json" };

	for (auto sceneName : sceneNames)
	{
		rapidjson::Document document;
		Json::Load(sceneName, document);
		m_scene->Read(document);
	}

	m_scene->Initialize();

	ADD_OBSERVER(PlayerDead, CoolGame::OnPlayerDead)

	return true;
}

void CoolGame::Shutdown()
{
	m_scene->RemoveAll();
}

void CoolGame::Update(float dt)
{
	m_scene->Update(dt);
}

void CoolGame::Draw(Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void CoolGame::OnPlayerDead(const Event& event)
{
	std::cout << "player dead :(" << endl;
}

void CoolGame::OnAddPoints(const Event& event)
{
}
