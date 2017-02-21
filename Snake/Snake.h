#pragma once
#include "vector"
#include <queue>
#include <SFML/Graphics.hpp>

class Snake
{
public:
	Snake();
	void update();
	void move(sf::Vector2f newSpeed);
	void eat();

	sf::Vector2f getPos();
	std::vector <sf::Vector2f> getBody();

	void setPos(sf::Vector2f newPos);

private:
	sf::Vector2f pos;
	sf::Vector2f speed;
	std::vector <sf::Vector2f> body;
	std::queue <sf::Vector2f> dirQue;
};

