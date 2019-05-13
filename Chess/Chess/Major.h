#pragma once
#include "Figure.h"
class Major_black :
	public Figure
{
public:
	static sf::Texture texture;
	Major_black() : Figure()
	{
		texture.loadFromFile("major_black.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Major_black() {};
};
sf::Texture Major_black::texture = sf::Texture();

class Major_white :
	public Figure
{
public:
	static sf::Texture texture;
	Major_white() : Figure()
	{
		texture.loadFromFile("major_white.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Major_white() {};
};
sf::Texture Major_white::texture = sf::Texture();