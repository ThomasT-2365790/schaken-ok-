#pragma once
#include "cord.h"
#include "color.h"
#include "what.h"
#include <vector>

class stuk {

public:
	stuk(color kleur, cord coord,what wat); //constructor
	color getcolor();
	void movestuk(cord& nieuw);
	cord getcord();
	what getwhat();
	bool is_mog_bew(cord verschil,cord nu);
	bool coordinaatvergelijker_stuk(cord one, cord two);
private:
	color collor;
	cord coordinaat;
	what wat;
	std::vector<cord> bew_pawn;

};