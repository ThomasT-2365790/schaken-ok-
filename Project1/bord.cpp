#include "bord.h"
#include "cord.h"
#include <iostream>
#include <vector>

bord::bord()
{
	setpion(pion{ color('W'), cord(1, 2) });
}

void bord::printbord()
{
	for (pion pionw : whitepions)
	{
		std::cout << 'W' << "pionw.getcord()" << std::endl;

	}
	for (pion pionb : blackpions)
	{
		std::cout << 'B' << "pionb.getcord()" << std::endl;

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
