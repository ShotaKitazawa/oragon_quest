#pragma once

#include <iostream>
#include "Map.h"

class Creature {
       protected:
	int x;
	int y;
	int hp;
	int maxHp;
	int mp;
	int maxMp;
	// int hungry;
	// int maxHungry;
	int strength;
	char symbol;
	std::string name;

       public:
	Creature(int x, int y, int hp, int maxHp, int mp, int maxMp,
		 int strength, char symbol, std::string name)
	    : x(x),
	      y(y),
	      hp(hp),
	      maxHp(maxHp),
	      mp(mp),
	      maxMp(maxMp),
	      strength(strength),
	      symbol(symbol),
	      name(name) {}
	//	void hit(Creature *) = 0;
	//	void move(int x, int y) = 0;

	char getSymbol() { return symbol; }
	void move(int xx, int yy) {
		this->x = xx;
		this->y = yy;
	}
	void setX(int n) { x = n; }
	void setY(int n) { y = n; }
	void setHp(int n) { hp = n; }
	void setMp(int n) { mp = n; }
	int getX() { return x; }
	int getY() { return y; }
	std::string getName() { return name; }
	int getHp() { return hp; }
	int getMp() { return mp; }
	int getStrength() { return strength; }
};
