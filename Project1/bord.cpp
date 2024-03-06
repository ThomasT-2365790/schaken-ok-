#include "bord.h"
#include "cord.h"
#include <iostream>
#include <vector>
#include "color.h"

bord::bord()
{
	setpion(pion{ color::W, cord(1, 2) });
}

void bord::printbord()
{
	for (pion pionw : whitepions)
	{
		std::cout << "W ";
		pionw.printpion();

	}
	for (pion pionb : blackpions)
	{
		std::cout << "B ";
		pionb.printpion();

	}
}

void bord::setpion(pion p) {

	if (p.getcolor() == color::W) {
		whitepions.push_back(p);
	}
	else if(p.getcolor() == color::B){
		blackpions.push_back(p);
	}

}

void bord::playw(cord nu, cord nieuw) {
	for (pion pionwit : whitepions)
	{
		if (pionwit.covergelijker(pionwit.getcord(),nu)) {
			pionwit.movepion(nieuw);
			break;

		}
	}
}
