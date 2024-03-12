#pragma once
#include <vector>
#include "pawn.h"

class bord {
	
public:
	bord();
	void printbord();
	void setpion(pawn p);
	void play(cord nu, cord nieuw);
	cord isPionAt(cord c);
	bool coordinaatvergelijker_inbord(cord a, cord b);
	color geefkleurvanco(cord a);
	what geefstuk(cord a);
	void printwhat(what a);
private:
	std::vector <pawn> whitepions;
	std::vector <pawn> blackpions;
};
