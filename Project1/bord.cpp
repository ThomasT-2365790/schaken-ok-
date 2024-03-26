#include "bord.h"
#include "cord.h"
#include <iostream>
#include <vector>
#include "color.h"
#include <string>
#include "pawn.h"


bord::bord()
{
	setstuk(pawn{ color::W, cord(2, 1)});
	setstuk(pawn{ color::W, cord(2, 2)});
	setstuk(pawn{ color::W, cord(2, 3)});
	setstuk(pawn{ color::W, cord(2, 4)});
	setstuk(pawn{ color::W, cord(2, 5)});
	setstuk(pawn{ color::W, cord(2, 6)});
	setstuk(pawn{ color::W, cord(2, 7)});
	setstuk(pawn{ color::W, cord(2, 8)});

	setstuk(pawn{ color::B, cord(7, 1)});
	setstuk(pawn{ color::B, cord(7, 2)});
	setstuk(pawn{ color::B, cord(7, 3)});
	setstuk(pawn{ color::B, cord(7, 4)});
	setstuk(pawn{ color::B, cord(7, 5)});
	setstuk(pawn{ color::B, cord(7, 6)});
	setstuk(pawn{ color::B, cord(7, 7)});
	setstuk(pawn{ color::B, cord(7, 8)});


}
bool bord::coordinaatvergelijker_inbord(cord a, cord b)
{
	if ((a.getkolom() == b.getkolom()) and (a.getrij() == b.getrij()))
	{
		return true;
	}
	return false;

}
void bord::printwhat(what a) {
	switch (a)
	{
	case what::PAWN:
		std::cout << " P ";
		break;
	case what::HORSE:
		std::cout << " H ";
		break;
	case what::KING:
		std::cout << " K ";
		break;
	case what::QUEEN:
		std::cout << " Q ";
		break;
	case what::ROOK:
		std::cout << " R ";
		break;
	case what::BISHOP:
		std::cout << " B ";
		break;
	}
}
cord bord::isPionAt(cord c) {
	for (stuk* pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw->getcord(),c )) {
			return pw->getcord(); // Coördinaat gevonden
		}
	}
	for (stuk* pb : blackpions) {
		if (coordinaatvergelijker_inbord(pb->getcord(), c)) {
			return pb->getcord(); // Coördinaat gevonden
		}
	}
	return cord(0,0); // Coördinaat niet gevonden
}

color bord::geefkleurvancoinbord(cord a) {
	for (stuk* pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw->getcord(), a)) {
			return color::W; // Coördinaat gevonden
		}
		
	}
	return color::B;
}
what bord::geefstuk(cord a) {
	for (stuk* k : whitepions)
	{
		if (coordinaatvergelijker_inbord(k->getcord(), a))
			return k->getwhat();
	}
	for (stuk* k : blackpions)
	{
		if (coordinaatvergelijker_inbord(k->getcord(), a))
			return k->getwhat();
	}

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
				color kleur = geefkleurvancoinbord(cord(verticaal, horizontaal));
				what waat = geefstuk(cord(verticaal, horizontaal));
				if (kleur == color::W)
				{
					std::cout << GREEN_COLOR;
					printwhat(waat);
					std::cout <<RESET_COLOR;
				}
				else
				{
					std::cout << RED_COLOR;
					printwhat(waat);
					std::cout << RESET_COLOR;
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

void bord::setstuk(stuk p) {
	stuk* newPiece = new stuk(p);
	if (p.getcolor() == color::W) {
		whitepions.push_back(newPiece);
	}
	else if(p.getcolor() == color::B){
		blackpions.push_back(newPiece);
	}

}

void bord::play(cord nu, cord nieuw) {

	for (stuk* piontomove : whitepions)
	{	
		if (coordinaatvergelijker_inbord(nu, piontomove->getcord())){
			piontomove
		}

		
	}

	for (stuk* piontomove : blackpions)
	{


		
	}
}



void bord::kill(cord to_kill) {
	int tellerw = 0;
	for (stuk* piontomove : whitepions)
	{
		if (coordinaatvergelijker_inbord(piontomove->getcord(), to_kill)) {
			whitepions.erase(whitepions.begin() + tellerw);
			return;
		}
		++tellerw;
	}
	int tellerb = 0;
	for (stuk* piontomove : blackpions)
	{
		if (coordinaatvergelijker_inbord(piontomove->getcord(), to_kill)) {
			blackpions.erase(blackpions.begin() + tellerb);
			return;
		}
		++tellerb;
	}
}