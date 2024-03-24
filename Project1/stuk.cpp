#include "stuk.h"
#include "color.h"
#include <iostream>

stuk::stuk(color kleur, cord coord) :collor{ kleur }, coordinaat{ coord } {}


color stuk::getcolor()
{
	return collor;
}

void stuk::movestuk(cord& nieuw)
{
	coordinaat = nieuw;
}

cord stuk::getcord()
{
	return coordinaat;
}

what stuk::getwhat() {
	return wat;
}
bool stuk::coordinaatvergelijker_stuk(cord a, cord b)
{
	if ((a.getkolom() == b.getkolom()) and (a.getrij() == b.getrij()))
	{
		return true;
	}
	return false;
}