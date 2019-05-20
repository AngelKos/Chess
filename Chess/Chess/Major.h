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
		class_name = "Major_black";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Major_black() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (abs(oldPos.x - newPos.x) == abs(oldPos.y - newPos.y)) return true;
		return false;
	}
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
		class_name = "Major_white";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Major_white() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (abs(oldPos.x - newPos.x) == abs(oldPos.y - newPos.y)) return true;
		return false;
	}
};
sf::Texture Major_white::texture = sf::Texture();