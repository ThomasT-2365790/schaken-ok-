#pragma once
#include "cord.h"
class speler {

public:
	speler(color kleur_van_speler);
	void movestuk(cord nu, cord nieuw);//deze functie veranderd/verwijderd enkel (geen controles)

private:
	color kleur;
protected:
	bord& spelbord;
};