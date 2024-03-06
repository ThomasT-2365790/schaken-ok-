#pragma once
#include "cord.h"
#include "color.h"
#include <tuple>

class pion {

public:
	pion(color kleur, cord coord); //constructor
	color getcolor();
	void movepion(cord nieuw);
	cord getcord();
	bool covergelijker(cord self,cord other);
	void printpion();
private:
	color collor;
	cord coordinaat;
};