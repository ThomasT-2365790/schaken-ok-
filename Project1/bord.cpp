#include "bord.h"
#include "cord.h"
#include <iostream>
#include <vector>
#include "color.h"
#include <string>
#include "Piece.h"


Bord::Bord()
{
	setstuk(Pawn{ Color::W, Cord(2, 1)});
	setstuk(Pawn{ Color::W, Cord(2, 2)});
	setstuk(Pawn{ Color::W, Cord(2, 3)});
	setstuk(Pawn{ Color::W, Cord(2, 4)});
	setstuk(Pawn{ Color::W, Cord(2, 5)});
	setstuk(Pawn{ Color::W, Cord(2, 6)});
	setstuk(Pawn{ Color::W, Cord(2, 7)});
	setstuk(Pawn{ Color::W, Cord(2, 8)});

	setstuk(Pawn{ Color::B, Cord(7, 1)});
	setstuk(Pawn{ Color::B, Cord(7, 2)});
	setstuk(Pawn{ Color::B, Cord(7, 3)});
	setstuk(Pawn{ Color::B, Cord(7, 4)});
	setstuk(Pawn{ Color::B, Cord(7, 5)});
	setstuk(Pawn{ Color::B, Cord(7, 6)});
	setstuk(Pawn{ Color::B, Cord(7, 7)});
	setstuk(Pawn{ Color::B, Cord(7, 8)});


}
bool Bord::coordinaatvergelijker_inbord(Cord a, Cord b)
{
	if ((a.getkolom() == b.getkolom()) and (a.getrij() == b.getrij()))
	{
		return true;
	}
	return false;

}
void Bord::printwhat(what a) {
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
Cord Bord::isPionAt(Cord c) {
	for (Stuk* pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw->getcord(),c )) {
			return pw->getcord(); // Coördinaat gevonden
		}
	}
	for (Stuk* pb : blackpions) {
		if (coordinaatvergelijker_inbord(pb->getcord(), c)) {
			return pb->getcord(); // Coördinaat gevonden
		}
	}
	return Cord(0,0); // Coördinaat niet gevonden
}

Color Bord::geefkleurvancoinbord(Cord a) {
	for (Stuk* pw : whitepions) {
		if (coordinaatvergelijker_inbord(pw->getcord(), a)) {
			return Color::W; // Coördinaat gevonden
		}
		
	}
	return Color::B;
}
what Bord::geefstuk(Cord a) {
	for (Stuk* k : whitepions)
	{
		if (coordinaatvergelijker_inbord(k->getcord(), a))
			return k->getwhat();
	}
	for (Stuk* k : blackpions)
	{
		if (coordinaatvergelijker_inbord(k->getcord(), a))
			return k->getwhat();
	}

}
void Bord::printbord()
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
			if (coordinaatvergelijker_inbord(isPionAt(Cord(verticaal, horizontaal)), Cord(0, 0)))
			{
				std::cout << " - ";
			}
			else
			{
				Color kleur = geefkleurvancoinbord(Cord(verticaal, horizontaal));
				what waat = geefstuk(cord(verticaal, horizontaal));
				if (kleur == Color::W)
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

void Bord::setstuk(Stuk p) {
	Stuk* newPiece = new Stuk(p);
	if (p.getcolor() == Color::W) {
		whitepions.push_back(newPiece);
	}
	else if(p.getcolor() == Color::B){
		blackpions.push_back(newPiece);
	}

}

void Bord::play(Cord nu, Cord nieuw) {

	for (Stuk* piontomove : stukken)
	{	
		if (coordinaatvergelijker_inbord(nu, piontomove->getcord())){
			piontomove->movestuk(nieuw);
		}
	}




void Bord::kill(Cord to_kill) {
	int tellerw = 0;
	for (Stuk* piontomove : whitepions)
	{
		if (coordinaatvergelijker_inbord(piontomove->getcord(), to_kill)) {
			whitepions.erase(whitepions.begin() + tellerw);
			return;
		}
		++tellerw;
	}
	int tellerb = 0;
	for (Stuk* piontomove : blackpions)
	{
		if (coordinaatvergelijker_inbord(piontomove->getcord(), to_kill)) {
			blackpions.erase(blackpions.begin() + tellerb);
			return;
		}
		++tellerb;
	}
}