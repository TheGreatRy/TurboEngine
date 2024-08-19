#include "CircleCollisionComponent.h"
#include "Framework/Actor.h"

FACTORY_REGISTER(CircleCollisionComponent)

bool CircleCollisionComponent::CheckCollision(const CollisionComponent* collision)
{
    float rOne = radius;
    float rTwo = (dynamic_cast<const CircleCollisionComponent*>(collision))->radius;

    float distance = owner->transform.position.Distance(collision->owner->transform.position);

    return distance <= (rOne + rTwo);
}

void CircleCollisionComponent::Read(const json_t& value)
{
    READ_DATA(value, radius);
}

void CircleCollisionComponent::Write(json_t& value)
{
}

void CircleCollisionComponent::Initialize()
{
}

void CircleCollisionComponent::Update(float dt)
{
}
