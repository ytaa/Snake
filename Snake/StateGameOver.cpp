#include "stdafx.h"
#include "StateGameOver.h"
#include <iostream>


StateGameOver::StateGameOver(ProgramContext* _context)
:context(_context)
{
}

StateId::State StateGameOver::run()
{
	sf::RenderWindow& window = context->window;

	while (window.isOpen())
	{
		auto state = handleEvents();
		if (state != StateId::State::gameOver) return state;
		render();
	}
	return StateId::State::exit;
}

StateId::State StateGameOver::handleEvents()
{
	sf::Event event;
	sf::RenderWindow& window = context->window;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window.close();

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::R:
				context->score = 0;
				return StateId::State::game;
				break;
			case sf::Keyboard::E:
				return StateId::State::exit;
				break;
			}
		}
	}
	return StateId::State::gameOver;
}

void StateGameOver::render()
{
	auto& window = context->window;
	auto windowSize = window.getSize().x;
	std::string scoreStr = std::to_string(context->score);
	window.clear();

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
	{
		// error...
	}
	sf::Text text;
	text.setFont(font); 
	text.setCharacterSize(24); 
	text.setFillColor(sf::Color::White);

	text.setString("GAMEOVER");
	text.setPosition((windowSize - text.getGlobalBounds().width) / 2, 100);
	window.draw(text);

	text.setString("Your score is: "+scoreStr);
	text.setPosition((windowSize - text.getGlobalBounds().width) / 2, 200);
	window.draw(text);

	text.setString("Press R to Restart");
	text.setPosition((windowSize - text.getGlobalBounds().width) / 2, 300);
	window.draw(text);

	text.setString("Press E to Exit");
	text.setPosition((windowSize - text.getGlobalBounds().width) / 2, 400);
	window.draw(text);


	window.display();
}