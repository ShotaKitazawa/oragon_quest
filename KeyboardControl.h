#pragma once

#include "Control.h"
#include "Creature.h"
#include "Map.h"
#include "Ora.h"

class Map;
class Creature;

class KeyboardControl : public Control {
       public:
	bool movepre(Creature* c1, Creature* c2) {
		char c;
		while (true) {
			std::cout
			    << "How do you move?\nh:left , j:down , k:up , "
			       "l:right\n>  ";
			std::cin >> c;
			if (c == 'h') tmp = 0;
			if (c == 'j') tmp = 1;
			if (c == 'k') tmp = 2;
			if (c == 'l') tmp = 3;
			if (tmp == 0 || tmp == 1 || tmp == 2 || tmp == 3)
				return checkpre(c1, c2);
		}
	}
	void move(Map* map, Creature* ora) {
		check(map, ora, tmp);
		tmp = -1;
	}
};
