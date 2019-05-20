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
		class_name = "Soldier_black";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Soldier_black() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (oldPos.y - newPos.y == 75 && abs(oldPos.x - newPos.x) <= 75) return true;
		if (oldPos.y == 475 && oldPos.y - newPos.y == 75 * 2 && abs(oldPos.x - newPos.x) == 0) return true;
		return false;
	}
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
		class_name = "Soldier_white";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Soldier_white() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (- oldPos.y + newPos.y == 75) return true;
		if (oldPos.y == 100 && - oldPos.y + newPos.y == 75 * 2) return true;
		return false;
	}
};
sf::Texture Soldier_white::texture = sf::Texture();


