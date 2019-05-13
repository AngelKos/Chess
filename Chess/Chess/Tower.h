#pragma once
#include "Figure.h"
class Tower_black :
	public Figure
{
public:
	static sf::Texture texture;
	Tower_black() : Figure()
	{
		texture.loadFromFile("tower_black.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Tower_black() {};
};
sf::Texture Tower_black::texture = sf::Texture();

class Tower_white :
	public Figure
{
public:
	static sf::Texture texture;
	Tower_white() : Figure()
	{
		texture.loadFromFile("tower_white.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Tower_white() {};
};
sf::Texture Tower_white::texture = sf::Texture();