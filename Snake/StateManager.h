#pragma once
#include "ProgramContext.h"
#include "StateId.h"
#include "State.h"

class StateManager
{
public:
	StateManager(ProgramContext* _context);
	~StateManager();
	void run();
	State* factory();
private:
	ProgramContext* context;
	StateId::State crStateId;
	State* crStateOb;
};

