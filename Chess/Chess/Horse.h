#pragma once
#include "Figure.h"
class Horse_black :
	public Figure
{
public:
	static sf::Texture texture;
	Horse_black() : Figure()
	{
		texture.loadFromFile("C:\\Users\\User\\Documents\\Informatics\\Chess\\Chess\\horse_black.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Horse_black() {};
};
sf::Texture Horse_black::texture = sf::Texture();
class Horse_white :
	public Figure
{
public:
	static sf::Texture texture;
	Horse_white() : Figure()
	{
		texture.loadFromFile("C:\\Users\\User\\Documents\\Informatics\\Chess\\Chess\\horse_white.png");
		sprite = sf::Sprite(texture);
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Horse_white() {};
};
sf::Texture Horse_white::texture = sf::Texture();