#include "stdafx.h"
#include "StateManager.h"
#include "StateId.h"
#include "State.h"
#include "StateGame.h"
#include "StateGameOver.h"
#include "Game.h"

StateManager::StateManager(ProgramContext* _context)
:context(_context)
,crStateId(StateId::State::game)
,crStateOb(NULL)
{
}

StateManager::~StateManager()
{
	delete crStateOb;
}

void StateManager::run()
{
	while (crStateId != StateId::State::exit)
	{
		if (crStateOb == NULL)
		{
			crStateOb = factory();
		}
		else
		{
			crStateId = crStateOb->run();
			delete crStateOb;
			crStateOb = NULL;
		}
	}
}

State* StateManager::factory()
{
	switch (crStateId)
	{
	case StateId::State::game:
		return new StateGame(context);
		break;
	case StateId::State::gameOver:
		return new StateGameOver(context);
		break;
	}
	return NULL;
}

