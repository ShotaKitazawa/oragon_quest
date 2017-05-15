#pragma once

#include "Creature.h"
#include "Monster.h"

class Gon : public Monster {
       public:
	Gon(int x, int y) : Monster(x, y, 20, 20, 100, 100, 1, 'G',"Gon") {}
};
