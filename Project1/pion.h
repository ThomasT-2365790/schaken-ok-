#pragma once
#include "cord.h"
#include "color.h"
#include <tuple>

class pion {

public:
	pion(color kleur, cord coord); //constructor
	char getcolor();
	void movepion(cord nieuw);
	std::tupl getcord();

private:
	color color;
	cord coordinaat;
};