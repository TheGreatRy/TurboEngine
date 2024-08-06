#pragma once
#include "../Resources/Resource.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/Font.h"

struct Color;

class Text
{
public:
	Text() = default;
	Text(res_t<Font> font) : m_font{ font } {}
	~Text();

	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, int x, int y);
	void SetFont(res_t<Font> font) { m_font = font; }

private:
	res_t<Font> m_font;
	SDL_Texture* m_texture{ nullptr };
};
