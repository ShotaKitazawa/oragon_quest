#pragma once

#include "Creature.h"
#include "Map.h"

class Map;
class Creature;

class Control {
       protected:
	static int tmp;

       public:
	virtual void move(Map*, Creature*) = 0;
	virtual bool movepre(Creature*, Creature*) = 0;

	bool checkpre(Creature* c1, Creature* c2) {
		if (tmp == 0) {
			if (c1->getX() != 0) {
				if (c1->getX() - 1 == c2->getX() &&
				    c1->getY() == c2->getY())
					return true;
				else
					c1->move(c1->getX() - 1, c1->getY());
			} else
				tmp = -1;
		} else if (tmp == 1) {
			if (c1->getY() != 9) {
				if (c1->getX() == c2->getX() &&
				    c1->getY() + 1 == c2->getY())
					return true;
				else
					c1->move(c1->getX(), c1->getY() + 1);
			} else
				tmp = -1;
		} else if (tmp == 2) {
			if (c1->getY() != 0) {
				if (c1->getX() == c2->getX() &&
				    c1->getY() - 1 == c2->getY())
					return true;
				else
					c1->move(c1->getX(), c1->getY() - 1);
			} else
				tmp = -1;
		} else if (tmp == 3) {
			if (c1->getX() != 9) {
				if (c1->getX() + 1 == c2->getX() &&
				    c1->getY() == c2->getY())
					return true;
				else
					c1->move(c1->getX() + 1, c1->getY());
			} else
				tmp = -1;
		}
		return false;
	}
	void check(Map* map, Creature* c, int a) {
		if (tmp != -1) {
			if (tmp == 0) {
				map->setCreature(c, c->getX(), c->getY());
				map->setCreature(NULL, c->getX() + 1,
						 c->getY());
			} else if (tmp == 1) {
				map->setCreature(c, c->getX(), c->getY());
				map->setCreature(NULL, c->getX(),
						 c->getY() - 1);
			} else if (tmp == 2) {
				map->setCreature(c, c->getX(), c->getY());
				map->setCreature(NULL, c->getX(),
						 c->getY() + 1);
			} else if (tmp == 3) {
				map->setCreature(c, c->getX(), c->getY());
				map->setCreature(NULL, c->getX() - 1,
						 c->getY());
			}
		}
	}
	int random() {
		srand(time(NULL));
		return rand() % 4;
	}
	bool hit(Creature* c1, Creature* c2) {
		c2->setHp(c2->getHp() - c1->getStrength());
		if (c2->getHp() <= 0) {
			delete c2;
			return true;
		}
		return false;
	}
};
