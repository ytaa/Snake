#include "stdafx.h"
#include "StateGame.h"
#include "StateId.h"
#include "ProgramContext.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include "Random.h"

#include <iostream>



StateGame::StateGame(ProgramContext* _context)
:context(_context)
,snake(Snake::Snake())
,fruit()
,fps(20)
,scale(0.05f)
,border(false)
{
}


StateId::State StateGame::run()
{
	auto& window = context->window;
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	sf::Clock fpsController;
	spawnFruit();
	while (window.isOpen())
	{
		handleEvents();
		if (fpsController.getElapsedTime().asMilliseconds() > 1000/ static_cast<int>(fps))
		{
			snake.update();
			if (handleCollisions())return StateId::State::gameOver;
			render();
			fpsController.restart();
		}
	}

	return StateId::State::exit;
}

void StateGame::handleEvents()
{
	sf::Event event;
	auto& window = context->window;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window.close();

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				snake.move(sf::Vector2f(0,-1));
				break;
			case sf::Keyboard::A:
				snake.move(sf::Vector2f(-1, 0));
				break;
			case sf::Keyboard::S:
				snake.move(sf::Vector2f(0, 1));
				break;
			case sf::Keyboard::D:
				snake.move(sf::Vector2f(1, 0));
				break;
			case sf::Keyboard::E:
				snake.eat();
				break;
			case sf::Keyboard::O:
				if(fps>1)fps--;
				break;
			case sf::Keyboard::P:
				if (fps<20)fps++;
				break;
			case sf::Keyboard::B:
				if (border)border = false;
				else border = true;
				break;
			}
		}
	}
}

bool StateGame::handleCollisions()
{
	auto snakePos = snake.getPos();
	
	//check collision with border 
	float maxPos = (1 / scale)-1;
	if (snakePos.x < 0) 
	{
		if (border)return true;
		snake.setPos(sf::Vector2f(maxPos, snakePos.y));
	}
	else if (snakePos.x > maxPos)
	{
		if (border)return true;
		snake.setPos(sf::Vector2f(0, snakePos.y));
	}
	if (snakePos.y < 0)
	{
		if (border)return true;
		snake.setPos(sf::Vector2f(snakePos.x, maxPos));
	}
	else if (snakePos.y > maxPos) 
	{
		if (border)return true;
		snake.setPos(sf::Vector2f(snakePos.x, 0));
	}

	//check collision with body
	auto& body = snake.getBody();
	for (size_t i = 0; i < body.size() - 1; i++)
	{
		if (body[i] == snakePos)return true;
	}

	//check collision with fruit
	if (snakePos == fruit)
	{
		snake.eat();
		context->score++;
		//in case snake is too big
		if (body.size() >= (1+maxPos)*(1+maxPos))return true;

		spawnFruit();
	}

	return false;

}

void StateGame::spawnFruit()
{
	float maxPos = (1 / scale) - 1;
	std::vector <sf::Vector2f>& body = snake.getBody();
	sf::Vector2f rVect;
	while (true)
	{
		rVect = sf::Vector2f(rnd::rInt(0, maxPos), rnd::rInt(0, maxPos));
		bool isInBody = false;
		for (size_t i = 0; i < body.size(); i++)
		{
			if (rVect == body[i])isInBody=true;
		}
		if(!isInBody)break;
	}
	fruit = rVect;
}

void StateGame::render()
{
	auto& window = context->window;
	//sf::Color(147, 219, 162)
	window.clear(sf::Color(0, 0, 0));

	std::vector <sf::Vector2f>& body = snake.getBody();

	size_t posMod = static_cast<std::size_t>(window.getSize().x*scale);
	//fillColor(124, 196, 139)
	sf::Color fillColor(50, 50, 50);

	//snake
	for (size_t i = 0; i < body.size(); i++)
	{
		sf::RectangleShape snakeShape(sf::Vector2f(static_cast<float>(posMod), static_cast<float>(posMod)));
		snakeShape.setFillColor(fillColor);
		snakeShape.setPosition(body[i].x*posMod,body[i].y*posMod);
		window.draw(snakeShape);
	}

	//fruit
	{
		sf::RectangleShape fruitShape(sf::Vector2f(static_cast<float>(posMod/3), static_cast<float>(posMod/3)));
		fruitShape.setFillColor(fillColor);
		fruitShape.setPosition(fruit.x*posMod+posMod/3,fruit.y*posMod);
		window.draw(fruitShape);
		fruitShape.setPosition(fruit.x*posMod, fruit.y*posMod + posMod / 3);
		window.draw(fruitShape);
		fruitShape.setPosition(fruit.x*posMod + (posMod / 3)*2, fruit.y*posMod + posMod / 3);
		window.draw(fruitShape);
		fruitShape.setPosition(fruit.x*posMod + posMod / 3, fruit.y*posMod + (posMod / 3)*2);
		window.draw(fruitShape);
	}

	//border
	if (border)
	{
		auto winSize = window.getSize().x;
		sf::RectangleShape borderLineShape(sf::Vector2f(winSize, winSize*0.005));
		borderLineShape.setFillColor(fillColor);

		borderLineShape.setPosition(0, 0);
		window.draw(borderLineShape);
		
		borderLineShape.setPosition(0, winSize*0.995);
		window.draw(borderLineShape);

		borderLineShape.rotate(90);
		borderLineShape.setPosition(winSize*0.005, 0);
		window.draw(borderLineShape);

		borderLineShape.setPosition(winSize, 0);
		window.draw(borderLineShape);
	}

	window.display();
}
