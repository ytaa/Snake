#include "stdafx.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include "ProgramContext.h"
#include "StateManager.h"
#include <iostream>
#include <Windows.h>


Game::Game()
:window(sf::VideoMode(800, 800), "Snake window", sf::Style::Titlebar | sf::Style::Close)
,context(ProgramContext::ProgramContext(window))
,stateManager(StateManager::StateManager(&context))
{
}

void Game::run()
{
	stateManager.run();
}

