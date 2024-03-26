#include "stuk.h"
#include "color.h"
#include <iostream>

Stuk::Stuk(Color kleur, Cord coord) :collor{ kleur }, coordinaat{ coord } {}


Color Stuk::getcolor()
{
	return collor;
}

void Stuk::movestuk(Cord& nieuw)
{
	coordinaat = nieuw;
}

Cord Stuk::getcord()
{
	return coordinaat;
}

bool Stuk::coordinaatvergelijker_stuk(Cord a, Cord b)
{
	if ((a.getkolom() == b.getkolom()) and (a.getrij() == b.getrij()))
	{
		return true;
	}
	return false;
}

