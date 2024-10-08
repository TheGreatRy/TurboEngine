#pragma once

// core
#include "Core/ETime.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"
#include "Core/EString.h"
#include "Core/Json.h"
#include "Core/Singleton.h"
#include "Core/Factory.h"
#include "Core/Serializable.h"

//systems
// framework
#include "Framework/Actor.h"
#include "Framework/Game.h"
#include "Framework/Object.h"
#include "Framework/Scene.h"
//components
#include "Components/Component.h"
#include "Components/RenderComponent.h"
#include "Components/TextureComponent.h"
#include "Components/TextureAnimationComponent.h"
#include "Components/TextComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/EnginePhysComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/CircleCollisionComponent.h"
#include "Components/AudioComponent.h"
#include "Components/TilemapComponent.h"
#include "Components/Box2DPhysicsComponent.h"
//renderer
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include "Renderer/Particle.h"
#include "Renderer/Model.h"
#include "Renderer/Color.h"
#include "Renderer/Texture.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
//resources
#include "Resources/Resource.h"
#include "Resources/ResourceManager.h"
//input
#include "Input/Input.h"
//audio
#include "Audio/Audio.h"
//math
#include "Math/Vector2.h"
#include "Math/MathUtil.h"
#include "Math/Random.h"
#include "Math/Transform.h"
#include "Math/Rect.h"
//Event
#include "Event/EventSystem.h"
//Physics
#include "Physics/Physics.h"
//standard headers
#include <SDL.h>
#include <fmod.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initalize();
	void Shutdown();
	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	Time& GetTime() { return *m_time; }
	ParticleSystem& GetPartSys() { return *m_partSys; }
	Physics& GetPhysics() { return *m_physics; }


	bool IsQuit() { return quit; }

private:
	bool quit{ false };

	std::unique_ptr<Physics> m_physics;
	std::unique_ptr<Renderer> m_renderer{ nullptr };
	std::unique_ptr<Time> m_time{ nullptr };
	std::unique_ptr<Input> m_input{ nullptr };
	std::unique_ptr<Audio> m_audio{ nullptr };
	std::unique_ptr<ParticleSystem> m_partSys{ nullptr };
};
