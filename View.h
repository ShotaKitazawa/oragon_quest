#pragma once
#include "Map.h"
#include "Creature.h"

class Map;
class Creature;

class View{
public:
	virtual void draw(Map& map) = 0;
	virtual void write(Map& map,Creature* c) = 0;
	virtual ~View(){}
};
