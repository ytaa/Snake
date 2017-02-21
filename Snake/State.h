#pragma once
#include "StateId.h"
class State
{
public:
	virtual StateId::State run() = 0;
};

