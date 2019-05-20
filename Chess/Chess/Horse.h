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
		class_name = "Horse_black";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Horse_black() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (abs(oldPos.x - newPos.x) == 3 * 75 && abs(oldPos.y - newPos.y) == 75) return true;
		if (abs(oldPos.y - newPos.y) == 3 * 75 && abs(oldPos.x - newPos.x) == 75) return true;
		return false;
	}
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
		class_name = "Horse_white";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Horse_white() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (abs(oldPos.x - newPos.x) == 2 * 75 && abs(oldPos.y - newPos.y) == 75) return true;
		if (abs(oldPos.y - newPos.y) == 2 * 75 && abs(oldPos.x - newPos.x) == 75) return true;
		return false;
	}
};
sf::Texture Horse_white::texture = sf::Texture();