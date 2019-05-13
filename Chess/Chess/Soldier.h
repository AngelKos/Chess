#pragma once
#include "Figure.h"
class Soldier_black :
	public Figure
{
public:
	static sf::Texture texture;
	Soldier_black() : Figure()
	{
		texture.loadFromFile("soldier_black.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Soldier_black() {};
};
sf::Texture Soldier_black::texture = sf::Texture();

class Soldier_white :
	public Figure
{
public:
	static sf::Texture texture;
	Soldier_white() : Figure()
	{
		texture.loadFromFile("soldier_white.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Soldier_white() {};
};
sf::Texture Soldier_white::texture = sf::Texture();


