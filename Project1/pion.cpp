#include "pion.h"
#include "color.h"
#include <iostream>

pion::pion(color kleur, cord coord) :collor{ kleur }, coordinaat{ coord }{}

color pion::getcolor()
{
	return collor;
}

void pion::movepion(cord& nieuw)
{
	coordinaat=nieuw;
}

cord pion::getcord()
{
	return coordinaat;
}


void pion::printpion() {
    std::cout << "(" << coordinaat.getrij() << ',' << coordinaat.getkolom() << ")" << std::endl;

}