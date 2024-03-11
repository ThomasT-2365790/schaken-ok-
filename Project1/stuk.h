#pragma once
#include "cord.h"
#include "color.h"

class stuk {

public:
	stuk(color kleur, cord coord); //constructor
	color getcolor();
	void movepion(cord& nieuw);
	cord getcord();
	void printpion();
private:
	color collor;
	cord coordinaat;
};