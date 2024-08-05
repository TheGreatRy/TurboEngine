#pragma once
#include "../Resources/Resource.h"
#include <string>
struct Vector2;

class Texture : public Resource
{	
public:
	friend class Renderer;
	Texture() = default;
	~Texture();
	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, class Renderer& renderer);

	Vector2 GetSize();

private:
	struct SDL_Texture* m_texture{ nullptr };
};