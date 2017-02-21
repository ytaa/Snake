#pragma once
#include <SFML/Graphics.hpp>

struct ProgramContext
{
	ProgramContext::ProgramContext(sf::RenderWindow& _window)
	:window(_window)
	{
	}

	sf::RenderWindow& window;
	
	size_t score;
};

