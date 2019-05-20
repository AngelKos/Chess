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
		class_name = "Tower_black";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Tower_black() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (oldPos.y - newPos.y == 0) return true;
		if (oldPos.x - newPos.x == 0) return true;
		return false;
	}
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
		class_name = "Tower_white";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Tower_white() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (oldPos.y - newPos.y == 0) return true;
		if (oldPos.x - newPos.x == 0) return true;
		return false;
	}
};
sf::Texture Tower_white::texture = sf::Texture();