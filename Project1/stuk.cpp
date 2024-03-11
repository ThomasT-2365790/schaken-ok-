#include "stuk.h"
#include "color.h"
#include <iostream>

stuk::stuk(color kleur, cord coord) :collor{ kleur }, coordinaat{ coord } {}

color stuk::getcolor()
{
	return collor;
}

void stuk::movepion(cord& nieuw)
{
	coordinaat = nieuw;
}

cord stuk::getcord()
{
	return coordinaat;
}


void stuk::printpion() {
	std::cout << "(" << coordinaat.getrij() << ',' << coordinaat.getkolom() << ")" << std::endl;

}