#include <iostream>
#include <vector>
#include <string>

#include "Bord.h"
#include "Cord.h"
#include "Color.h"

#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Tower.h"
#include "Bishop.h"
#include "King.h"
#


Bord::Bord()
{
	for (int index = 0;index < 9;++index){
		pieces.push_back(new Pawn{ Color::W, Cord(2, index)});
		pieces.push_back(new Pawn{ Color::B, Cord(7, index) });

	}
	pieces.push_back(new Knight{ Color::W, Cord(1, 2) });
	pieces.push_back(new Knight{ Color::W, Cord(1, 7) });
	pieces.push_back(new Knight{ Color::B, Cord(8, 2) });
	pieces.push_back(new Knight{ Color::B, Cord(8, 7) });

	pieces.push_back(new Tower{ Color::W, Cord(1, 1) });
	pieces.push_back(new Tower{ Color::W, Cord(1, 8) });
	pieces.push_back(new Tower{ Color::B, Cord(8, 1) });
	pieces.push_back(new Tower{ Color::B, Cord(8, 8) });

	pieces.push_back(new Bishop{ Color::W, Cord(1, 3) });
	pieces.push_back(new Bishop{ Color::W, Cord(1, 6) });
	pieces.push_back(new Bishop{ Color::B, Cord(8, 3) });
	pieces.push_back(new Bishop{ Color::B, Cord(8, 6) });
	
	pieces.push_back(new King{ Color::W, Cord(1, 5) });
	pieces.push_back(new King{ Color::B, Cord(8, 5) });

	pieces.push_back(new Queen{ Color::W, Cord(1, 4) });
	pieces.push_back(new Queen{ Color::B, Cord(8, 4) });


}



void Bord::printbord()
{
	const std::string RESET_COLOR = "\033[0m";
	const std::string RED_COLOR = "\033[31m";
	const std::string GREEN_COLOR = "\033[32m";
	int tellerrand = 8;
	std::cout << std::endl;
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
				for (Piece* _piece : pieces) {
					if (compare_cord(_piece->getcord(), Cord(verticaal, horizontaal)))//piece found
					{
						if (_piece->getcolor() == Color::W)
						{
							std::cout << GREEN_COLOR;
							_piece->print_type();
							std::cout << RESET_COLOR;
						}
						else
						{
							std::cout << RED_COLOR;
							_piece->print_type();
							std::cout << RESET_COLOR;
						}

						break;
					}
				}
				
			}
		std::cout << std::endl;
	}
	std::cout << "  A  B  C  D  E  F  G  H" << std::endl << std::endl;
}





void Bord::play(Cord now, Cord after) {

	for (Piece* piontomove : pieces)
	{
		if (compare_cord(now, piontomove->getcord())) {
			piontomove->movepiece(after);
		}
	}
}



Cord Bord::piece_at(Cord _cord) {
	for (Piece* _piece : pieces) {
		if (compare_cord(_piece->getcord(), _cord)) {
			return _piece->getcord(); // Coördinaat gevonden
		}
	}
	return Cord(0, 0); // Coördinaat niet gevonden
}

bool Bord::compare_cord(Cord one, Cord two) {
	if ((one.getcolum() == two.getcolum()) and (one.getrow() == two.getrow()))
	{
		return true;
	}
	return false;
}

Color Bord::color_cord(Cord _cord) {
	for (Piece* _piece : pieces) {
		if (compare_cord(_piece->getcord(), _cord)) {
			return Color::W; // Coördinaat gevonden
		}

	}
}

bool Bord::in_bounce(Cord _cord) {
	return (0<=_cord.getrow()<9 && 0 <= _cord.getcolum() < 9);
	}

void Bord::kill(Cord to_kill) {
	int tellerw = 0;
	for (Piece* _piece : pieces){
		if (compare_cord(_piece->getcord(), to_kill))
		{
			auto to_erase = std::find(pieces.begin(), pieces.end(), _piece);//find zoekt hier voor ons de juiste waarde om te erasen
			pieces.erase(to_erase);
			break;
		}
	}
}

