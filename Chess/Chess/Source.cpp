#include <SFML/Graphics.hpp>
#include <time.h>
#include<iostream>
#include"Connector.hpp"
#include "Horse.h"
#include "King.h"
#include "Major.h"
#include "Queen.h"
#include "Soldier.h"
#include "Tower.h"
#include<vector>
using namespace sf;
int size = 75;
std::vector<Figure> f;
std::string toChessNote(Vector2f p)
{
	std::string s = "";
	s += char(p.x / size + 97);
	s += char(p.y / size + 49);
	return s;
}
Vector2f toCoord(char a, char b)
{
	int x = int(a) - 97;
	int y = int(b) - 49;
	return Vector2f(x*size + 25, y*size + 25);
}
void move(std::string str)
{
	Vector2f oldPos = toCoord(str[0], str[1]);
	Vector2f newPos = toCoord(str[2], str[3]);
	for (int i = 0; i < f.size(); i++) if (f[i].sprite.getPosition() == newPos) f.erase(f.begin() + i);
	for (int i = 0; i < f.size(); i++) if (f[i].sprite.getPosition() == oldPos) f[i].sprite.setPosition(newPos);
}
std::string position = "";
void LoadPosition()
{
	if (f.size() <= 0) f.push_back(King_black());
	f[0].sprite.setPosition(250, 550);
	if (f.size() <= 1) f.push_back(King_white());
	f[1].sprite.setPosition(250, 25);
	if (f.size() <= 2) f.push_back(Queen_black());
	f[2].sprite.setPosition(325, 550);
	if (f.size() <= 3) f.push_back(Queen_white());
	f[3].sprite.setPosition(325, 25);
	if (f.size() <= 4) f.push_back(Tower_black());
	f[4].sprite.setPosition(25, 550);
	if (f.size() <= 5) f.push_back(Tower_black());
	f[5].sprite.setPosition(550, 550);
	if (f.size() <= 6) f.push_back(Tower_white());
	f[6].sprite.setPosition(25, 25);
	if (f.size() <= 7) f.push_back(Tower_white());
	f[7].sprite.setPosition(550, 25);
	if (f.size() <= 8) f.push_back(Major_black());
	f[8].sprite.setPosition(175, 550);
	if (f.size() <= 9) f.push_back(Major_black());
	f[9].sprite.setPosition(400, 550);
	if (f.size() <= 10) f.push_back(Major_white());
	f[10].sprite.setPosition(175, 25);
	if (f.size() <= 11) f.push_back(Major_white());
	f[11].sprite.setPosition(400, 25);
	if (f.size() <= 12) f.push_back(Horse_black());
	f[12].sprite.setPosition(100, 550);
	if (f.size() <= 13) f.push_back(Horse_black());
	f[13].sprite.setPosition(475, 550);
	if (f.size() <= 14) f.push_back(Horse_white());
	f[14].sprite.setPosition(100, 25);
	if (f.size() <= 15) f.push_back(Horse_white());
	f[15].sprite.setPosition(475, 25);
	for (int i = 16; i < 24; i++)
	{
		if (f.size() <= i) f.push_back(Soldier_black());
		f[i].sprite.setPosition(25 + (i - 16) * 75, 475);
	}
	for (int i = 24; i < 32; i++)
	{
		if(f.size() <= i) f.push_back(Soldier_white());
		f[i].sprite.setPosition(25 + (i - 24) * 75, 100);
	}
	for (int i = 0; i < position.length(); i += 5)
	{
		move(position.substr(i, 4));
	}
}
int main()
{
	RenderWindow window(VideoMode(650, 650), "Chess Game");
	char* engine = new char[14];
	engine[0] = 's';
	engine[1] = 't';
	engine[2] = 'o';
	engine[3] = 'c';
	engine[4] = 'k';
	engine[5] = 'f';
	engine[6] = 'i';
	engine[7] = 's';
	engine[8] = 'h';
	engine[9] = '.';
	engine[10] = 'e';
	engine[11] = 'x';
	engine[12] = 'e';
	engine[13] = '/0';
	ConnectToEngine(engine);
	sf::Texture tboard = sf::Texture();
	tboard.loadFromFile("Chess board.png");
	Sprite sboard(tboard);
	window.draw(sboard);
	f.push_back(King_black());
	f[0].sprite.setPosition(250, 550);
	f[0].Draw(&window);
	f.push_back(King_white());
	f[1].sprite.setPosition(250, 25);
	f[1].Draw(&window);
	f.push_back(Queen_black());
	f[2].sprite.setPosition(325, 550);
	f[2].Draw(&window);
	f.push_back(Queen_white());
	f[3].sprite.setPosition(325, 25);
	f[3].Draw(&window);
	f.push_back(Tower_black());
	f[4].sprite.setPosition(25, 550);
	f[4].Draw(&window);
	f.push_back(Tower_black());
	f[5].sprite.setPosition(550, 550);
	f[5].Draw(&window);
	f.push_back(Tower_white());
	f[6].sprite.setPosition(25, 25);
	f[6].Draw(&window);
	f.push_back(Tower_white());
	f[7].sprite.setPosition(550, 25);
	f[7].Draw(&window);
	f.push_back(Major_black());
	f[8].sprite.setPosition(175, 550);
	f[8].Draw(&window);
	f.push_back(Major_black());
	f[9].sprite.setPosition(400, 550);
	f[9].Draw(&window);
	f.push_back(Major_white());
	f[10].sprite.setPosition(175, 25);
	f[10].Draw(&window);
	f.push_back(Major_white());
	f[11].sprite.setPosition(400, 25);
	f[11].Draw(&window);
	f.push_back(Horse_black());
	f[12].sprite.setPosition(100, 550);
	f[12].Draw(&window);
	f.push_back(Horse_black());
	f[13].sprite.setPosition(475, 550);
	f[13].Draw(&window);
	f.push_back(Horse_white());
	f[14].sprite.setPosition(100, 25);
	f[14].Draw(&window);
	f.push_back(Horse_white());
	f[15].sprite.setPosition(475, 25);
	f[15].Draw(&window);
	for (int i = 16; i < 24; i++)
	{
		f.push_back(Soldier_black());
		f[i].sprite.setPosition(25 + (i - 16) * 75, 475);
		f[i].Draw(&window);
	}
	for (int i = 24; i < 32; i++) 
	{
		f.push_back(Soldier_white());
		f[i].sprite.setPosition(25 + (i - 24) * 75, 100);
		f[i].Draw(&window);
	}
	window.display();
	bool Move = false;
	double mx = 0, my = 0;
	Vector2f oldPos, newPos;
	std::string str;
	int n = 0;
	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) window.close();
			if (e.type == Event::KeyPressed) if (e.key.code == Keyboard::BackSpace)
			{
				if(position.length() > 5) position.erase(position.length() - 6, 5);
				else position.clear();
				LoadPosition();
			}
			window.clear();
			window.draw(sboard);
			for (int i = 0; i < f.size(); i++) f[i].Draw(&window);
			window.display();
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
					for(int i = 0; i < f.size(); i++)
						if (f[i].sprite.getGlobalBounds().contains(pos.x, pos.y))
						{
							Move = true;
							n = i;
							mx = pos.x - f[i].sprite.getPosition().x;
							my = pos.y - f[i].sprite.getPosition().y;
							oldPos = f[i].sprite.getPosition();
						}
			window.clear();
			window.draw(sboard);
			for (int i = 0; i < f.size(); i++) f[i].Draw(&window);
			window.display();
			if (e.type == Event::MouseButtonReleased)
				if (e.key.code == Mouse::Left)
				{
					Move = false;
					Vector2f p = f[n].sprite.getPosition() + Vector2f(size / 2, size / 2);
					newPos = Vector2f(size*int(p.x / size) + 25, size*int(p.y / size) + 25);
					str = toChessNote(oldPos) + toChessNote(newPos);
					move(str);
					position += str + " ";
					std::cout << str << std::endl;
					f[n].sprite.setPosition(newPos);
				}
			window.clear();
			window.draw(sboard);
			for (int i = 0; i < f.size(); i++) f[i].Draw(&window);
			window.display();
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			str = getNextMove(position);
			oldPos = toCoord(str[0], str[1]);
			newPos = toCoord(str[2], str[3]);
			for (int i = 0; i < f.size(); i++) if (f[i].sprite.getPosition() == oldPos) n = i;
			for (int i = 0; i < 50; i++)
			{
				Vector2f p = newPos - oldPos;
				f[n].sprite.move(p.x / 50, p.y / 50);
				window.draw(sboard);
				for (int j = 0; j < f.size(); j++)
				{
					f[i].Draw(&window);
					f[n].Draw(&window);
				}
				window.display();
			}
			move(str);
			position += str + " ";
			f[n].sprite.setPosition(newPos);
		}
		if (Move) f[n].sprite.setPosition(pos.x - mx, pos.y - my);
		window.clear();
		window.draw(sboard);
		for (int i = 0; i < f.size(); i++) f[i].Draw(&window);
		window.display();
	}
	CloseConnection();
	return 0;
}