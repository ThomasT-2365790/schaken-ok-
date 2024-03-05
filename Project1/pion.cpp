#include "pion.h"

pion::pion()

color pion::getcolor()
{
	return color;
}

void pion::movepion(cord nieuw)
{
	coordinaat = nieuw;
}

std::tuple pion::getcord()
{
	return coordinaat
}