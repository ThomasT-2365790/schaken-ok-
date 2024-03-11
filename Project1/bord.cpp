#include "bord.h"
#include "cord.h"
#include <iostream>
#include <vector>
#include "color.h"
#include <string>

bord::bord()
{
	setpion(pawn{ color::W, cord(2, 1) });
	setpion(pawn{ color::W, cord(2, 2) });
	setpion(pawn{ color::W, cord(2, 3) });
	setpion(pawn{ color::W, cord(2, 4) });
	setpion(pawn{ color::W, cord(2, 5) });
	setpion(pawn{ color::W, cord(2, 6) });
	setpion(pawn{ color::W, cord(2, 7) });
	setpion(pawn{ color::W, cord(2, 8) });

	setpion(pawn{ color::B, cord(7, 1) });
	setpion(pawn{ color::B, cord(7, 2) });
	setpion(pawn{ color::B, cord(7, 3) });
	setpion(pawn{ color::B, cord(7, 4) });
	setpion(pawn{ color::B, cord(7, 5) });
	setpion(pawn{ color::B, cord(7, 6) });
	setpion(pawn{ color::B, cord(7, 7) });
	setpion(pawn{ color::B, cord(7, 8) });


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
	for (pawn pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw.getcord(),c )) {
			return pw.getcord(); // Coördinaat gevonden
		}
	}
	for (pawn& pb : blackpions) {
		if (coordinaatvergelijker_inbord(pb.getcord(), c)) {
			return pb.getcord(); // Coördinaat gevonden
		}
	}
	return cord(0,0); // Coördinaat niet gevonden
}

color bord::geefkleurvanco(cord a) {
	for (pawn pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw.getcord(), a)) {
			return color::W; // Coördinaat gevonden
		}
		
	}
	return color::B;
}
void bord::printbord()
{
	const std::string RESET_COLOR = "\033[0m";
	const std::string RED_COLOR = "\033[31m";
	const std::string GREEN_COLOR= "\033[32m";
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
					std::cout <<GREEN_COLOR<< " W "<<RESET_COLOR;
				}
				else
				{
					std::cout << RED_COLOR << " B " << RESET_COLOR;
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

void bord::setpion(pawn p) {

	if (p.getcolor() == color::W) {
		whitepions.push_back(p);
	}
	else if(p.getcolor() == color::B){
		blackpions.push_back(p);
	}

}

void bord::play(cord nu, cord nieuw) {
	int tellerw = 0;
	for (pawn pionwit : whitepions)
	{	
		if (coordinaatvergelijker_inbord(pionwit.getcord(),nu)) {
			whitepions.erase(whitepions.begin()+tellerw);
			pawn pionnieuw(color::W, nieuw);
			whitepions.push_back(pionnieuw);
			return;

		}
		++tellerw;
	}
	int tellerb = 0;
	for (pawn pionwit : blackpions)
	{
		if (coordinaatvergelijker_inbord(pionwit.getcord(), nu)) {
			blackpions.erase(blackpions.begin() + tellerb);
			pawn pionnieuw(color::B, nieuw);
			blackpions.push_back(pionnieuw);
			return;

		}
		++tellerb;
	}
}
