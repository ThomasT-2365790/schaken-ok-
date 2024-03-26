#pragma once
#include "Cord.h"
#include "Bord.h"
class Player {

public:
	Player(Color _color);
	void movestuk(Cord _now, Cord _new);//deze functie veranderd/verwijderd enkel (geen controles)

private:
	Color _color;

protected:
	Bord playbord;
};