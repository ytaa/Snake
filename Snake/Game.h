#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "ProgramContext.h"
#include "StateManager.h"

class Game
{
public:
	Game();
	void run();
	
private:
	sf::RenderWindow window;
	ProgramContext context;
	StateManager stateManager;
};

