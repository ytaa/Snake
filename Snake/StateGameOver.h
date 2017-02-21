#pragma once
#include "State.h"
#include "ProgramContext.h"
class StateGameOver : public State
{
public:
	StateGameOver(ProgramContext* _context);
	StateId::State run();
private:
	ProgramContext* context;
	
	StateId::State handleEvents();
	void render();
};

