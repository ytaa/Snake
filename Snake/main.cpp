#include "stdafx.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include "Shobjidl.h"
#include <functional>
#include "Snake.h"
#include "Game.h"

int main()
{
	FreeConsole();
	Game game;
	game.run();
	//system("pause");
}

	/*sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(600, 600), "Snake window", sf::Style::Default, settings);
	//window.setPosition(sf::Vector2i(10, 50));
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(5);
	window.setKeyRepeatEnabled(false);
	window.setActive(false);*/

	//sf::Clock fpsController;
/*
	while (window.isOpen())
	{
		handleWindowEvents(window, crState);

		switch (crState)
		{
		case game:
			if (fpsController.getElapsedTime().asMilliseconds() >= 50)
			{
				updateGame(crState, playerSnake);
				renderGame(window, playerSnake);
				fpsController.restart();
			}
			break;
		}

		Sleep(1);
	}

	return 0;
}
*/
/*


void handleWindowEvents(sf::RenderWindow& window, gameStates& crState)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window.close();

		if (event.type == sf::Event::KeyPressed)
		{
			handleKeyInput(event.key.code, crState);
		}
	}
}

void handleKeyInput(sf::Keyboard::Key& key, gameStates& crState)
{
	switch (crState)
	{
	case game:
		switch (key)
		{
		case sf::Keyboard::W:
			std::cout << "key: W" << std::endl;
			break;
		case sf::Keyboard::A:
			std::cout << "key: A" << std::endl;
			break;
		case sf::Keyboard::S:
			std::cout << "key: S" << std::endl;
			break;
		case sf::Keyboard::D:
			std::cout << "key: D" << std::endl;
			break;
		}
	}
}

void updateGame(gameStates& crState, Snake& playerSnake)
{
	playerSnake.update();
}

void renderGame(sf::RenderWindow& window, Snake& playerSnake)
{
	window.clear(sf::Color::Magenta);

	sf::RectangleShape snakeShape(sf::Vector2f(10, 10));
	snakeShape.setFillColor(sf::Color::Blue);
	snakeShape.setPosition(playerSnake.getX(), playerSnake.getY());

	window.draw(snakeShape);

	window.display();
}

*/