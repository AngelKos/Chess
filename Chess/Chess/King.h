#pragma once
#include "Figure.h"
class King_black :
	public Figure
{
public:
	static sf::Texture texture;
	King_black() : Figure()
	{
		texture.loadFromFile("king_black.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~King_black() {};
};
sf::Texture King_black::texture = sf::Texture();
class King_white :
	public Figure
{
public:
	static sf::Texture texture;
	King_white() : Figure()
	{
		texture.loadFromFile("king_white.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~King_white() {};
};
sf::Texture King_white::texture = sf::Texture();