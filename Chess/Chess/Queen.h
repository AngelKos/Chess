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
		class_name = "Queen_black";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Queen_black() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos)
	{
		return true;
		/*int dx = 0, dy = 0;
		if (abs(oldPos.x - newPos.x) == abs(oldPos.y - newPos.y))
		{
			int dx = 0, int dy = 0;
			if (newPos.x > oldPos.x) dx = 1;
			else dx = -1;
			if (newPos.y > oldPos.y) dy = 1;
			else dy = -1;
		}
		else if (abs(oldPos.x - newPos.x) == 0)
		{
			dx = 0;
			if (newPos.y > oldPos.y) dy = 1;
			else dy = -1;
		}
		else if (abs(oldPos.y - newPos.y) == 0)
		{
			dy = 0;
			if (newPos.x > oldPos.x) dx = 1;
			else dx = -1;
		}
		else return false;*/
	}
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
		class_name = "Queen_white";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~Queen_white() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) { return true; }
};
sf::Texture Queen_white::texture = sf::Texture();