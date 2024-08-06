#include "TextureComponent.h"
#include "../Framework/Actor.h"
#include "../Renderer/Renderer.h"

void TextureComponent::Initialize()
{
	if (!textureName.empty())
	{
		
	}
}

void TextureComponent::Update(float dt)
{
}

void TextureComponent::Draw(Renderer& renderer)
{
	Transform transform = owner->GetTransform();
	renderer.DrawTexture(texture.get(), transform.position.x, transform.position.y, transform.rotation);
}
