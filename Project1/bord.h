#pragma once
#include <vector>
#include "stuk.h"
#include "cord.h"
#include "what.h"
#include "color.h"

class bord {
	
public:
	bord();
	void printbord();
	void setstuk(stuk piece);
	void play(cord now, cord after);
	cord isPionAt(cord coord);
	bool coordinaatvergelijker_inbord(cord one, cord two);
	color geefkleurvanco(cord coord);
	bool in_bounce(cord coord);
private:
	std::vector <stuk*> whitepions;
	std::vector <stuk*> blackpions;
};
