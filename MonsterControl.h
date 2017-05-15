#pragma once

#include "Control.h"
#include "Creature.h"
#include "Map.h"

class Map;
class Creature;

class MonsterControl: public Control{
	public:
		void move (Map* map, Creature* c){
			int a = random();
			check(map,c,a);
		}
		bool movepre(Creature* c1, Creature* c2) {}
};


