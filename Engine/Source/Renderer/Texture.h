#pragma once

#include <string>
class Vector2;

class Texture
{	
public:
	friend class Renderer;
	Texture() = default;
	~Texture();

	bool Load(const std::string& filename, class Renderer& renderer);

	Vector2 GetSize();

	

private:
	struct SDL_Texture* m_texture{ nullptr };
};