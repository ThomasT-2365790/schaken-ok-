#include "bord.h"
#include "cord.h"
#include <iostream>
#include <vector>
#include "color.h"

bord::bord()
{
	setpion(pion{ color::W, cord(2, 1) });
	setpion(pion{ color::W, cord(2, 2) });
	setpion(pion{ color::W, cord(2, 3) });
	setpion(pion{ color::W, cord(2, 4) });
	setpion(pion{ color::W, cord(2, 5) });
	setpion(pion{ color::W, cord(2, 6) });
	setpion(pion{ color::W, cord(2, 7) });
	setpion(pion{ color::W, cord(2, 8) });

	setpion(pion{ color::B, cord(7, 1) });
	setpion(pion{ color::B, cord(7, 2) });
	setpion(pion{ color::B, cord(7, 3) });
	setpion(pion{ color::B, cord(7, 4) });
	setpion(pion{ color::B, cord(7, 5) });
	setpion(pion{ color::B, cord(7, 6) });
	setpion(pion{ color::B, cord(7, 7) });
	setpion(pion{ color::B, cord(7, 8) });


}
bool bord::coordinaatvergelijker_inbord(cord a, cord b)
{
	if ((a.getkolom() == b.getkolom()) and (a.getrij() == b.getrij()))
	{
		return true;
	}
	return false;

}
cord bord::isPionAt(cord c) {
	for (pion pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw.getcord(),c )) {
			return pw.getcord(); // Coördinaat gevonden
		}
	}
	for (pion& pb : blackpions) {
		if (coordinaatvergelijker_inbord(pb.getcord(), c)) {
			return pb.getcord(); // Coördinaat gevonden
		}
	}
	return cord(0,0); // Coördinaat niet gevonden
}

color bord::geefkleurvanco(cord a) {
	for (pion pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw.getcord(), a)) {
			return color::W; // Coördinaat gevonden
		}
		
	}
	return color::B;
}
void bord::printbord()
{
	
	int tellerrand = 8;
	for (int verticaal = 8;verticaal >= 1;--verticaal)
	{
		std::cout << tellerrand;
		--tellerrand;
		for (int horizontaal=1;horizontaal<=8;++horizontaal)
			if (coordinaatvergelijker_inbord(isPionAt(cord(verticaal, horizontaal)), cord(0, 0)))
			{
				std::cout << " - ";
			}
			else
			{
				color kleur = geefkleurvanco(cord(verticaal, horizontaal));
				if (kleur == color::W)
				{
					std::cout << " W ";
				}
				else
				{
					std::cout << " B ";
				}
			}
		std::cout << std::endl;
	}
	std::cout << "  A  B  C  D  E  F  G  H"<<std::endl << std::endl;
	/*for (pion pionw : whitepions)
	{
		std::cout << "W ";
		pionw.printpion();

	}
	for (pion pionb : blackpions)
	{
		std::cout << "B ";
		pionb.printpion();

	}*/
}

void bord::setpion(pion p) {

	if (p.getcolor() == color::W) {
		whitepions.push_back(p);
	}
	else if(p.getcolor() == color::B){
		blackpions.push_back(p);
	}

}

void bord::play(cord nu, cord nieuw) {
	int tellerw = 0;
	for (pion pionwit : whitepions)
	{	
		if (coordinaatvergelijker_inbord(pionwit.getcord(),nu)) {
			whitepions.erase(whitepions.begin()+tellerw);
			pion pionnieuw(color::W, nieuw);
			whitepions.push_back(pionnieuw);
			return;

		}
		++tellerw;
	}
	int tellerb = 0;
	for (pion pionwit : blackpions)
	{
		if (coordinaatvergelijker_inbord(pionwit.getcord(), nu)) {
			blackpions.erase(blackpions.begin() + tellerb);
			pion pionnieuw(color::B, nieuw);
			blackpions.push_back(pionnieuw);
			return;

		}
		++tellerb;
	}
}
