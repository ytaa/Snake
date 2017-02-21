#include "stdafx.h"
#include "Snake.h"
#include "iostream"
#include <queue>

Snake::Snake()
: pos(2, 2)
, speed(1, 0)
, body({ pos - speed, pos })
, dirQue()
{
}

void Snake::update()
{
	if (dirQue.size() > 0)
	{
		if (dirQue.front() + speed != sf::Vector2f(0, 0))
		{
			speed = dirQue.front();
		}
		dirQue.pop();
	}

	pos = pos + speed;
	body.erase(body.begin());
	body.push_back(pos);
}

void Snake::move(sf::Vector2f newSpeed)
{
	if (dirQue.size() > 2)return;
	dirQue.push(newSpeed);
}

void Snake::eat()
{
	body.push_back(pos);
}

sf::Vector2f Snake::getPos()
{
	return pos;
}

std::vector <sf::Vector2f> Snake::getBody()
{
	return body;
}

void Snake::setPos(sf::Vector2f newPos)
{
	pos = newPos;
	body[body.size() - 1] = newPos;
}