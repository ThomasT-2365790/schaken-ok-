#pragma once
#include "cord.h"
#include "color.h"
#include <tuple>

class pion {

public:
	pion(color kleur, cord coord); //constructor
	color getcolor();
	void movepion(cord nieuw);
	std::tuple<int,int> getcord();
	bool covergelijker(std::tuple<int, int> self, std::tuple<int, int> other);
	void printpion();
private:
	color collor;
	cord coordinaat;
};