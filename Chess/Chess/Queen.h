#pragma once
#include "Figure.h"
class Queen_black :
	public Figure
{
public:
	static sf::Texture texture;
	Queen_black() : Figure()
	{
		texture.loadFromFile("queen_black.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Queen_black() {};
};
sf::Texture Queen_black::texture = sf::Texture();

class Queen_white :
	public Figure
{
public:
	static sf::Texture texture;
	Queen_white() : Figure()
	{
		texture.loadFromFile("queen_white.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Queen_white() {};
};
sf::Texture Queen_white::texture = sf::Texture();