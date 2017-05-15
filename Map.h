#pragma once
#include "def.h"
#include "View.h"
#include "Creature.h"
//#include "Item.h"
#include <cstdlib>

class Map {
       private:
	Creature* creatureMap[WIDTH][HEIGHT];
	// Item* itemMap[WIDTH][HEIGHT];
	View* view;

       public:
	Map() : view(NULL) {
		for (int x = 0; x < WIDTH; x++) {
			for (int y = 0; y < HEIGHT; y++) {
				creatureMap[x][y] = NULL;
				// itemMap[x][y] = NULL;
			}
		}
	}
	void setView(View& vp) { view = &vp; }
	void draw() { view->draw(*this); }
	Creature* getCreature(int x, int y) { return creatureMap[x][y]; }
	// Item* getItem(int x, int y) { return itemMap[x][y]; }
	void setCreature(Creature* c, int x, int y) { creatureMap[x][y] = c; }
	// void setItem(Item* i, int x, int y) { itemMap[x][y] = i; }
};
