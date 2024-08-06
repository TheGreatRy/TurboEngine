#include "../Framework/Actor.h"
#include "../Components/RenderComponent.h"

void Actor::Initialize()
{
	for (auto& component : m_components)
	{
		component->Initialize();
	}
}

void Actor::Update(float dt)
{
	if (m_lifespan != 0)
	{
		m_lifespan -= dt;
		if (m_lifespan <= 0)
		{
			m_destroy = true;
		}
	}
	for (auto& component : m_components)
	{
		component->Update(dt);
	}
	m_transform.position += (m_velocity * dt);
	m_velocity *= 1.0f / (1.0f + m_damping * dt);
}

void Actor::Draw(Renderer& renderer)
{
	if (m_destroy) return;
	for (auto& component : m_components)
	{
		RenderComponent* renderComp = dynamic_cast<RenderComponent*>(component.get());
		if (renderComp)
		{
			renderComp->Draw(renderer);
		}
	}
}

void Actor::AddComponent(std::unique_ptr<Component> component)
{
	component->owner = this;
	m_components.push_back(std::move(component));
}




