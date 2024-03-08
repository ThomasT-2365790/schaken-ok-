#pragma once
#include <vector>
#include "pion.h"

class bord {
	
public:
	bord();
	void printbord();
	void setpion(pion p);
	void play(cord nu, cord nieuw);
	cord isPionAt(cord c);
	bool coordinaatvergelijker_inbord(cord a, cord b);
	color geefkleurvanco(cord a);
private:
	std::vector <pion> whitepions;
	std::vector <pion> blackpions;
};
