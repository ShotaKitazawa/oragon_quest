#include <iostream>
#include "Control.h"
#include "Creature.h"
#include "Gon.h"
#include "KeyboardControl.h"
#include "Map.h"
#include "MonsterControl.h"
#include "Ora.h"
#include "TextView.h"
#include "View.h"
//

using namespace std;

int Control::tmp = -1;

int main() {
	View* v = new TextView();
	Map* m = new Map();
	Control* ctrl = new KeyboardControl();
	// Control* monctrl = new MonsterControl();
	Creature* ora = new Ora(0, 9);
	Creature* gon = new Gon(9, 0);
	m->setCreature(ora, 0, 9);
	m->setCreature(gon, 9, 0);
	v->draw(*m);

	v->write(*m, ora);
	v->write(*m, gon);
	cout << endl;
	while (true) {
		if (ctrl->movepre(ora, gon)) {  // Check ora crash gon
			if (ctrl->hit(ora, gon)) break;
		} else {
			ctrl->move(m, ora);
			// monctrl->move(m, gon);
		}
		v->draw(*m);
		cout << endl;
		v->write(*m, ora);
		v->write(*m, gon);
		cout << endl;
	}
	cout << "\n>>> Win!! <<<" << endl;
}
