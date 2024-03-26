#pragma once
#include "Cord.h"
class Player {

public:
	Player(Color color);
	void movestuk(Cord now, Cord new_cord);//deze functie veranderd/verwijderd enkel (geen controles)

private:
	Color _color;
};