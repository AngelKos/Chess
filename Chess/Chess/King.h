#pragma once
#include "Figure.h"
class King_black :
	public Figure
{
public:
	static sf::Texture texture;
	King_black() : Figure()
	{
		texture.loadFromFile("king_black.png");
		sprite = sf::Sprite(texture);
		class_name = "King_black";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~King_black() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (abs(oldPos.x - newPos.x) <= 75 && abs(oldPos.y - newPos.y) <= 75) return true;
		return false;
	}
};
sf::Texture King_black::texture = sf::Texture();
class King_white :
	public Figure
{
public:
	static sf::Texture texture;
	King_white() : Figure()
	{
		texture.loadFromFile("king_white.png");
		sprite = sf::Sprite(texture);
		class_name = "King_white";
	}
	void Draw(sf::RenderWindow* window) override
	{
		window->draw(sprite);
	}
	~King_white() {};
	bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) override
	{
		if (abs(oldPos.x - newPos.x) <= 75 && abs(oldPos.y - newPos.y) <= 75) return true;
		return false;
	}
};
sf::Texture King_white::texture = sf::Texture();