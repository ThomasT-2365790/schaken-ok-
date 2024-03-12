#pragma once
#include "cord.h"
#include "color.h"
#include "what.h"

class stuk {

public:
	stuk(color kleur, cord coord,what a); //constructor
	color getcolor();
	void movepion(cord& nieuw);
	cord getcord();
	void printpion();
	what getwhat();
private:
	what wat;
	color collor;
	cord coordinaat;
};