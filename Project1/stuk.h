#pragma once
#include "cord.h"
#include "color.h"
#include <vector>
#include "bord.h"

class stuk {

public:
	stuk(color kleur, cord coord); //constructor
	color getcolor();
	void movestuk(cord& nieuw);
	cord getcord();
	bool coordinaatvergelijker_stuk(cord one, cord two);

private:
	color collor;
	cord coordinaat;
protected:
	bord* naam;

	

};