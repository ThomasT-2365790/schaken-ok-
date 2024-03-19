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
	bool coordinaatvergelijker_stuk(cord one, cord two);

private:
	color collor;
	what wat;
protected:
	cord coordinaat;
	

};