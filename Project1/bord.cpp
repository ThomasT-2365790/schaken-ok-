#include "bord.h"
#include "cord.h"
#include <iostream>
#include <vector>
#include "color.h"

bord::bord()
{
	setpion(pion{ color::W, cord(1, 1) });
	setpion(pion{ color::W, cord(1, 2) });
	setpion(pion{ color::W, cord(1, 3) });
	setpion(pion{ color::W, cord(1, 4) });
	setpion(pion{ color::W, cord(1, 5) });
	setpion(pion{ color::W, cord(1, 6) });
	setpion(pion{ color::W, cord(1, 7) });
	setpion(pion{ color::W, cord(1, 8) });

	setpion(pion{ color::B, cord(7, 1) });
	setpion(pion{ color::B, cord(7, 2) });
	setpion(pion{ color::B, cord(7, 3) });
	setpion(pion{ color::B, cord(7, 4) });
	setpion(pion{ color::B, cord(7, 5) });
	setpion(pion{ color::B, cord(7, 6) });
	setpion(pion{ color::B, cord(7, 7) });
	setpion(pion{ color::B, cord(7, 8) });


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
	int teller = 0;
	for (pion pionwit : whitepions)
	{	
		if (pionwit.covergelijker(pionwit.getcord(),nu)) {
			whitepions.erase(whitepions.begin()+teller);
			pion pionnieuw(color::W, nieuw);
			whitepions.push_back(pionnieuw);
			break;

		}
		++teller;
	}
}

void bord::playb(cord nu, cord nieuw) {
	int teller = 0;
	for (pion pionwit : blackpions)
	{
		if (pionwit.covergelijker(pionwit.getcord(), nu)) {
			blackpions.erase(whitepions.begin() + teller);
			pion pionnieuw(color::B, nieuw);
			whitepions.push_back(pionnieuw);
			break;

		}
		++teller;
	}
}
