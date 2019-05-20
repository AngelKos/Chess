#pragma once
#include<SFML/Graphics.hpp>
class Figure
{
public:
	std::string class_name;
	sf::Sprite sprite;
	virtual void Draw(sf::RenderWindow * window)
	{
		window->draw(sprite);
	}
	Figure() 
	{
		class_name = "";
	}
	~Figure() {}
	virtual bool Check(sf::Vector2f oldPos, sf::Vector2f newPos) = 0;
};
	