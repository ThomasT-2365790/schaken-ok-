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

bool pion::covergelijker(cord self, cord other) {
	if (self.getkolom() == other.getkolom()) {
		if (self.getrij() == other.getkolom()) {
			return 1;
		}
	}
}

void pion::printpion() {
    std::cout << "(" << coordinaat.getrij() << ',' << coordinaat.getkolom() << ")" << std::endl;

}