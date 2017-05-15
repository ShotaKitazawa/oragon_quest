#pragma once

#include <iostream>
#include "Creature.h"
#include "Map.h"
#include "KeyboardControl.h"

class Map;

class Ora : public Creature {
	protected:
	int experience;
       public:
	Ora(int x = 0, int y = 0)
	    : Creature(x, y, 20, 20, 100, 100, 2, 'O', "Ora"), experience(0) {}
};
