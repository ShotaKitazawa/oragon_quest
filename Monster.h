#pragma once

#include "Creature.h"
#include <iostream>

class Monster : public Creature {
       public:
	Monster(int x, int y, int hp, int maxHp, int mp, int maxMp,
		int strength, char symbol, std::string name)
	    : Creature(x, y, hp, maxHp, mp, maxMp, strength, symbol,name) {}
};
