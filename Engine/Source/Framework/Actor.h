#pragma once
#include "Object.h"
#include "../Renderer/Model.h"
#include "../Components/Component.h"
#include <vector>
#include <memory>
#include <string>

class Renderer;
class Scene;

class Actor : public Object
{
public:
	Actor() = default;
	Actor(const Transform transform) : m_transform {transform} {}
	
	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);

	void SetDamping(float damping) { m_damping = damping; }
	void SetLifespan(float lifespan) { m_lifespan = lifespan; }

	const Transform& GetTransform() { return m_transform; }
	void SetTag(const std::string& tag) { m_tag = tag; }
	std::string& GetTag() { return m_tag; }
	void AddComponent(std::unique_ptr<Component> component);

	virtual void OnCollision(Actor* actor) {};

	float GetRadius() { return 0; }

	friend class Scene;

protected:
	std::string m_tag;
	bool m_destroy{ false };
	float m_lifespan = 0;

	Transform m_transform;
	Vector2 m_velocity{ 0,0 };
	float m_damping{ 0.0f };

	Scene* m_scene{ nullptr };
	std::vector<std::unique_ptr<Component>> m_components;

	// Inherited via Object
	void Initialize() override;
};
