#pragma once
#include<SFML/Graphics.hpp>
class Figure
{
public:
	sf::Sprite sprite;
	virtual void Draw(sf::RenderWindow * window)
	{
		window->draw(sprite);
	}
	Figure() {}
	~Figure() {}
};
