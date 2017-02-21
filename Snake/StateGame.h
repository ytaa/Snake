#pragma once
#include "State.h"
#include "StateId.h"
#include "ProgramContext.h"
#include "Snake.h"
class StateGame: public State
{
public:
	StateGame(ProgramContext* _context);
	StateId::State run();
private:
	ProgramContext* context;
	Snake snake;
	sf::Vector2f fruit;
	size_t fps;
	float scale;
	bool border;

	void handleEvents();
	bool handleCollisions();
	void spawnFruit();
	void render();
};

