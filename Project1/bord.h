#pragma once
#include <vector>
#include "pion.h"

class bord {

public:
	bord();
	void printbord();
	void setpion(pion p);
	void playw(cord nu, cord nieuw);
private:
	std::vector <pion> whitepions;
	std::vector <pion> blackpions;
};
