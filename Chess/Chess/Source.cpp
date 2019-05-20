#include <SFML/Graphics.hpp>
#include <time.h>
#include<iostream>
#include<string>
#include"Connector.hpp"
#include"Figure.h"
#include "Horse.h"
#include "King.h"
#include "Major.h"
#include "Queen.h"
#include "Soldier.h"
#include "Tower.h"
#include<vector>
using namespace sf;
int size = 75;
std::vector<std::shared_ptr<Figure>> f;
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
	//bool king = false;
	for (int i = 0; i < f.size(); i++) 
		if (f[i]->sprite.getPosition() == newPos)
		{
			/*if (f[i]->class_name != "King_white" && f[i]->class_name != "King_black")*/ f.erase(f.begin() + i);
			//else king = true;
		}
	for (int i = 0; i < f.size(); i++) if (f[i]->sprite.getPosition() == oldPos)
	{
		/*if (!king)*/ f[i]->sprite.setPosition(newPos);
		//else f[i]->sprite.setPosition(oldPos);
	}
}
bool Under_attack(std::string color, Vector2f Pos)
{
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->class_name.substr(f[i]->class_name.size() - 5, 5) != color) if (f[i]->Check(f[i]->sprite.getPosition(), Pos)) return true;
	}
	return false;
}
bool King_dead(std::string color)
{
	int n;
	if (color == "white") n = 1;
	else n = 0;
	Vector2f Pos = f[n]->sprite.getPosition();
	bool m1m1 = Under_attack(color, Vector2f(Pos.x - 1, Pos.y - 1));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x - 1, Pos.y - 1)) m1m1 = true;
	}
	bool m1z = Under_attack(color, Vector2f(Pos.x - 1, Pos.y));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x - 1, Pos.y)) m1z = true;
	}
	bool zm1 = Under_attack(color, Vector2f(Pos.x, Pos.y - 1));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x, Pos.y - 1)) zm1 = true;
	}
	bool p1p1 = Under_attack(color, Vector2f(Pos.x + 1, Pos.y + 1));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x + 1, Pos.y + 1)) p1p1 = true;
	}
	bool p1z = Under_attack(color, Vector2f(Pos.x + 1, Pos.y));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x + 1, Pos.y)) p1z = true;
	}
	bool zp1 = Under_attack(color, Vector2f(Pos.x, Pos.y + 1));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x, Pos.y + 1)) zp1 = true;
	}
	bool m1p1 = Under_attack(color, Vector2f(Pos.x - 1, Pos.y + 1));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x - 1, Pos.y + 1)) m1p1 = true;
	}
	bool p1m1 = Under_attack(color, Vector2f(Pos.x + 1, Pos.y - 1));
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i]->sprite.getPosition() == Vector2f(Pos.x + 1, Pos.y - 1)) p1m1 = true;
	}
	return Under_attack(color, Pos)
		&& m1m1
		&& m1z
		&& zm1
		&& p1p1
		&& p1z
		&& zp1
		&& m1p1
		&& p1m1;
}
std::string position = "";
void LoadPosition()
{
	f.clear();
	f.push_back(std::shared_ptr<King_black>(new King_black()));
	f[0]->sprite.setPosition(250, 550);
	f.push_back(std::shared_ptr<King_white>(new King_white()));
	f[1]->sprite.setPosition(250, 25);
	f.push_back(std::shared_ptr<Queen_black>(new Queen_black()));
	f[2]->sprite.setPosition(325, 550);
	f.push_back(std::shared_ptr<Queen_white>(new Queen_white()));
	f[3]->sprite.setPosition(325, 25);
	f.push_back(std::shared_ptr<Tower_black>(new Tower_black()));
	f[4]->sprite.setPosition(25, 550);
	f.push_back(std::shared_ptr<Tower_black>(new Tower_black()));
	f[5]->sprite.setPosition(550, 550);
	f.push_back(std::shared_ptr<Tower_white>(new Tower_white()));
	f[6]->sprite.setPosition(25, 25);
	f.push_back(std::shared_ptr<Tower_white>(new Tower_white()));
	f[7]->sprite.setPosition(550, 25);
	f.push_back(std::shared_ptr<Major_black>(new Major_black()));
	f[8]->sprite.setPosition(175, 550);
	f.push_back(std::shared_ptr<Major_black>(new Major_black()));
	f[9]->sprite.setPosition(400, 550);
	f.push_back(std::shared_ptr<Major_white>(new Major_white()));
	f[10]->sprite.setPosition(175, 25);
	f.push_back(std::shared_ptr<Major_white>(new Major_white()));
	f[11]->sprite.setPosition(400, 25);
	f.push_back(std::shared_ptr<Horse_black>(new Horse_black()));
	f[12]->sprite.setPosition(100, 550);
	f.push_back(std::shared_ptr<Horse_black>(new Horse_black()));
	f[13]->sprite.setPosition(475, 550);
	f.push_back(std::shared_ptr<Horse_white>(new Horse_white()));
	f[14]->sprite.setPosition(100, 25);
	f.push_back(std::shared_ptr<Horse_white>(new Horse_white()));
	f[15]->sprite.setPosition(475, 25);
	for (int i = 16; i < 24; i++)
	{
		f.push_back(std::shared_ptr<Soldier_black>(new Soldier_black()));
		f[i]->sprite.setPosition(25 + (i - 16) * 75, 475);
	}
	for (int i = 24; i < 32; i++)
	{
		f.push_back(std::shared_ptr<Soldier_white>(new Soldier_white()));
		f[i]->sprite.setPosition(25 + (i - 24) * 75, 100);
	}
	for (int i = 0; i < position.length(); i += 5)
	{
		move(position.substr(i, 4));
	}
}
int main()
{
	RenderWindow window(VideoMode(650, 650), "Chess Game");
	std::string path = "stockfish.exe";
	ConnectToEngine((char*)"stockfish.exe");
	sf::Texture tboard = sf::Texture();
	tboard.loadFromFile("Chess board.png");
	Sprite sboard(tboard);
	window.draw(sboard);
	f.push_back(std::shared_ptr<King_black>(new King_black()));
	f[0]->sprite.setPosition(250, 550);
	f.push_back(std::shared_ptr<King_white>(new King_white()));
	f[1]->sprite.setPosition(250, 25);
	f.push_back(std::shared_ptr<Queen_black>(new Queen_black()));
	f[2]->sprite.setPosition(325, 550);
	f.push_back(std::shared_ptr<Queen_white>(new Queen_white()));
	f[3]->sprite.setPosition(325, 25);
	f.push_back(std::shared_ptr<Tower_black>(new Tower_black()));
	f[4]->sprite.setPosition(25, 550);
	f.push_back(std::shared_ptr<Tower_black>(new Tower_black()));
	f[5]->sprite.setPosition(550, 550);
	f.push_back(std::shared_ptr<Tower_white>(new Tower_white()));
	f[6]->sprite.setPosition(25, 25);
	f.push_back(std::shared_ptr<Tower_white>(new Tower_white()));
	f[7]->sprite.setPosition(550, 25);
	f.push_back(std::shared_ptr<Major_black>(new Major_black()));
	f[8]->sprite.setPosition(175, 550);
	f.push_back(std::shared_ptr<Major_black>(new Major_black()));
	f[9]->sprite.setPosition(400, 550);
	f.push_back(std::shared_ptr<Major_white>(new Major_white()));
	f[10]->sprite.setPosition(175, 25);
	f.push_back(std::shared_ptr<Major_white>(new Major_white()));
	f[11]->sprite.setPosition(400, 25);
	f.push_back(std::shared_ptr<Horse_black>(new Horse_black()));
	f[12]->sprite.setPosition(100, 550);
	f.push_back(std::shared_ptr<Horse_black>(new Horse_black()));
	f[13]->sprite.setPosition(475, 550);
	f.push_back(std::shared_ptr<Horse_white>(new Horse_white()));
	f[14]->sprite.setPosition(100, 25);
	f.push_back(std::shared_ptr<Horse_white>(new Horse_white()));
	f[15]->sprite.setPosition(475, 25);
	for (int i = 16; i < 24; i++)
	{
		f.push_back(std::shared_ptr<Soldier_black>(new Soldier_black()));
		f[i]->sprite.setPosition(25 + (i - 16) * 75, 475);
	}
	for (int i = 24; i < 32; i++)
	{
		f.push_back(std::shared_ptr<Soldier_white>(new Soldier_white()));
		f[i]->sprite.setPosition(25 + (i - 24) * 75, 100);
	}
	for (int i = 0; i < 32; i++)
	{
		f[i]->Draw(&window);
	}
	window.display();
	bool Move = false;
	double mx = 0, my = 0;
	Vector2f oldPos, newPos;
	std::string str;
	int n = -1;
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
			for (int i = 0; i < f.size(); i++) f[i]->Draw(&window);
			window.display();
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
					for(int i = 0; i < f.size(); i++)
						if (f[i]->sprite.getGlobalBounds().contains(pos.x, pos.y))
						{
							Move = true;
							n = i;
							mx = pos.x - f[i]->sprite.getPosition().x;
							my = pos.y - f[i]->sprite.getPosition().y;
							oldPos = f[i]->sprite.getPosition();
						}
			window.clear();
			window.draw(sboard);
			for (int i = 0; i < f.size(); i++) f[i]->Draw(&window);
			window.display();
			if (e.type == Event::MouseButtonReleased)
				if (e.key.code == Mouse::Left)
				{
					Move = false;
					Vector2f p = f[n]->sprite.getPosition() + Vector2f(size / 2, size / 2);
					newPos = Vector2f(size*int(p.x / size) + 25, size*int(p.y / size) + 25);
					bool checked = true;
					checked = f[n]->Check(oldPos, newPos);
					if (checked)
					{
						bool cross = false;
						std::string color = f[n]->class_name.substr(f[n]->class_name.size() - 5, 5);
						for (int i = 0; i < f.size(); i++)
						{
							std::string color_cross = f[i]->class_name.substr(f[i]->class_name.size() - 5, 5);
							if (color_cross == color && newPos == f[i]->sprite.getPosition()) cross = true;
						}
						if (!cross)
						{
							str = toChessNote(oldPos) + toChessNote(newPos);
							move(str);
							position += str + " ";
							std::cout << str << std::endl;
							f[n]->sprite.setPosition(newPos);
						}
						else f[n]->sprite.setPosition(oldPos);
					}
					else
					{
						f[n]->sprite.setPosition(oldPos);
					}
				}
			window.clear();
			window.draw(sboard);
			for (int i = 0; i < f.size(); i++) f[i]->Draw(&window);
			window.display();
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			str = getNextMove(position);
			oldPos = toCoord(str[0], str[1]);
			newPos = toCoord(str[2], str[3]);
			for (int i = 0; i < f.size(); i++)
			{
				Vector2f Pos = f[i]->sprite.getPosition();
				if (Pos.x == oldPos.x && Pos.y == oldPos.y) n = i;
			}
			for (int i = 0; i < 500; i++)
			{
				Vector2f p = newPos - oldPos;
				f[n]->sprite.move(p.x / 500, p.y / 500);
				window.draw(sboard);
				for (int j = 0; j < f.size(); j++)
				{
					f[j]->Draw(&window);
					f[n]->Draw(&window);
				}
				window.display();
			}
			//move(str);
			position += str + " ";
			f[n]->sprite.setPosition(newPos);
			for (int i = 0; i < f.size(); i++)
			{
				Vector2f Pos = f[i]->sprite.getPosition();
				if (newPos.x == Pos.x && newPos.y == Pos.y && n != i)
				{
					f.erase(f.begin() + i);
					break;
				}
			}
		}
		if (Move) f[n]->sprite.setPosition(pos.x - mx, pos.y - my);
		window.clear();
		window.draw(sboard);
		for (int i = 0; i < f.size(); i++) f[i]->Draw(&window);
		window.display();
		//if (King_dead("black") || King_dead("white")) window.close();
	}
	CloseConnection();
	return 0;
}