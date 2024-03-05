#include "bord.h"
#include <iostream>
#include <vector>

bord::bord()
{
	pion p{ color('W'), cord(1, 2) };
	setpion(p);
}

void bord::printbord()
{
	for (pion pionw : whitepions)
	{
		std::cout << 'W' << getcord() << std::endl

	}
	for (pionb : blackpions)
	{
		std::cout << 'B' << getcord() << std::endl

	}
}

void bord::setpion(pion p) {

	if (p.getcolor() == 'W') {
		whitepions.push_back(p);
	}
	else {
		blackpions.push_back(p);
	}

}

void playw(cord nu, cord nieuw) {
	for (pion p : whitepions)
	{
		if (p.getcord == nu.getcord)
		{
			p.movepion(cord nieuw)
		}

	}
}

void playb(cord nu, cord nieuw) {
	for (pion p : blackpions)
	{
		if (p.getcord == nu.getcord)
		{
			p.movepion(cord nieuw)
		}

	}
}
