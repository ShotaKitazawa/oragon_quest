#include "View.h"
#include "def.h"
#include "Creature.h"
#include <cstdlib>
#include <iostream>

class TextView : public View {
       public:
	void draw(Map& map) {
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				Creature* c = map.getCreature(x, y);
				if (c == NULL) {
					// Item* ip = map.getItem(x, y);
					// if (ip == NULL)
					std::cout << ".";
					// else
					//	std::cout << ip->getSymbol();
				} else
					std::cout << c->getSymbol();
			}
			std::cout << std::endl;
		}
	}

	void write(Map& map, Creature* c) {
		std::cout << "[" << c->getName() << "] Hp: " << c->getHp()
			  << ", Mp: " << c->getMp() << std::endl;
	}
};
