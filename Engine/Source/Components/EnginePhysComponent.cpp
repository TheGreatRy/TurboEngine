#include "EnginePhysComponent.h"
#include "Framework/Actor.h"

FACTORY_REGISTER(EnginePhysComponent)

void EnginePhysComponent::Initialize()
{
}

void EnginePhysComponent::Read(const json_t& value)
{
	PhysicsComponent::Read(value);
}

void EnginePhysComponent::Write(json_t& value)
{
}

void EnginePhysComponent::Update(float dt)
{
	velocity += acceleration * dt;
	owner->transform.position += velocity * dt;

	velocity *= 1.0f / (1.0f + damping * dt);

	acceleration = Vector2{ 0,0 };
}

void EnginePhysComponent::ApplyForce(const Vector2& force)
{
	assert(mass != 0);
	acceleration += force / mass;
}

void EnginePhysComponent::ApplyTorque(float angle)
{
	owner->transform.rotation += angle;
}

void EnginePhysComponent::SetPosition(const Vector2& position)
{
	owner->transform.position = position;
}
