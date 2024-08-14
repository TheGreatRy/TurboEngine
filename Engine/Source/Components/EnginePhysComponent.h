#pragma once
#include "PhysicsComponent.h"

class EnginePhysComponent : public PhysicsComponent
{
public:
	CLASS_DECLARATION(EnginePhysComponent)

	void Initialize() override;
	void Update(float dt) override;

	void ApplyForce(const Vector2& force) override;
	void SetPosition(const Vector2& position) override;
	inline void SetVelocity(const Vector2& velocity) override { this->velocity = velocity; }
};