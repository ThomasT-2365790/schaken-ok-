#include "stuk.h"
#include "color.h"
#include <iostream>

stuk::stuk(color kleur, cord coord, what a) :collor{ kleur }, coordinaat{ coord },wat{ a } {}

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

what stuk::getwhat() {
	return wat;
}