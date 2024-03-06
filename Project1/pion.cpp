#include "pion.h"
#include "color.h"
#include <iostream>

pion::pion(color kleur, cord coord) :collor{ kleur }, coordinaat{ coord }{}

color pion::getcolor()
{
	return collor;
}

void pion::movepion(cord nieuw)
{
	std::get<0>(coordinaat.getcord()) = std::get<0>(nieuw.getcord());
}

std::tuple<int,int> pion::getcord()
{
	return coordinaat.getcord();
}

bool pion::covergelijker(std::tuple<int, int> self, std::tuple<int, int> other) {

    // Haal de coördinaten van de huidige pion op
    auto self_coords = self;
    int self_kolom = std::get<0>(self_coords);
    int self_rij = std::get<1>(self_coords);

    // Haal de coördinaten van de andere pion op
    auto other_coords = other;
    int other_kolom = std::get<0>(other_coords);
    int other_rij = std::get<1>(other_coords);

    // Controleer of de pionnen zich op dezelfde kolom of rij bevinden
    return self_kolom == other_kolom && self_rij == other_rij;


}

void pion::printpion() {
    std::cout << "(" << std::get<0>(coordinaat.getcord()) << ", " << std::get<1>(coordinaat.getcord()) << ")" << std::endl;

}