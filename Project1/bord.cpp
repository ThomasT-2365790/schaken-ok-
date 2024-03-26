#include "Bord.h"
#include "Cord.h"
#include <iostream>
#include <vector>
#include "Color.h"
#include <string>
#include "Pawn.h"


Bord::Bord()
{
	setpiece(Pawn{ Color::W, Cord(2, 1)});
	setpiece(Pawn{ Color::W, Cord(2, 2)});
	setpiece(Pawn{ Color::W, Cord(2, 3)});
	setpiece(Pawn{ Color::W, Cord(2, 4)});
	setpiece(Pawn{ Color::W, Cord(2, 5)});
	setpiece(Pawn{ Color::W, Cord(2, 6)});
	setpiece(Pawn{ Color::W, Cord(2, 7)});
	setpiece(Pawn{ Color::W, Cord(2, 8)});

	setpiece(Pawn{ Color::B, Cord(7, 1)});
	setpiece(Pawn{ Color::B, Cord(7, 2)});
	setpiece(Pawn{ Color::B, Cord(7, 3)});
	setpiece(Pawn{ Color::B, Cord(7, 4)});
	setpiece(Pawn{ Color::B, Cord(7, 5)});
	setpiece(Pawn{ Color::B, Cord(7, 6)});
	setpiece(Pawn{ Color::B, Cord(7, 7)});
	setpiece(Pawn{ Color::B, Cord(7, 8)});


}
bool Bord::compare_cord(Cord one, Cord two)
{
	if ((one.getcolum() == two.getcolum()) and (one.getrow() == two.getrow()))
	{
		return true;
	}
	return false;

}
void Bord::printbord()
{
	const std::string RESET_COLOR = "\033[0m";
	const std::string RED_COLOR = "\033[31m";
	const std::string GREEN_COLOR = "\033[32m";
	int tellerrand = 8;
	for (int verticaal = 8;verticaal >= 1;--verticaal)
	{
		std::cout << tellerrand;
		--tellerrand;
		for (int horizontaal = 1;horizontaal <= 8;++horizontaal)
			if (compare_cord(piece_at(Cord(verticaal, horizontaal)), Cord(0, 0)))
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
					std::cout << RESET_COLOR;
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
	std::cout << "  A  B  C  D  E  F  G  H" << std::endl << std::endl;
}

void Bord::setpiece(Piece _piece) {
	Piece* newPiece = new Piece(_piece);
	pieces.push_back(newPiece);
}

Cord Bord::piece_at(Cord _cord) {
	for (Piece* _piece : pieces) {
		if (compare_cord(_piece->getcord(),_cord )) {
			return _piece->getcord(); // Coördinaat gevonden
		}
	return Cord(0,0); // Coördinaat niet gevonden
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
Color Bord::color_cord(Cord _cord) {
	for (Piece* _piece : pieces) {
		if (coordinaatvergelijker_inbord(pw->getcord(), a)) {
			return Color::W; // Coördinaat gevonden
		}

	}
	return Color::B;
}