#include <iostream>
#include <vector>
#include <string>

#include "Bord.h"
#include "Cord.h"
#include "Color.h"
#include "Player.h"

#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Tower.h"
#include "Bishop.h"
#include "King.h"
#


Bord::Bord()
{
	for (int index = 0;index < 9;++index) {
		pieces.push_back(new Pawn{ Color::W, Cord(2, index) });
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
							std::cout<<" "<<_piece->return_type()<<" ";
							std::cout << RESET_COLOR;
						}
						else
						{
							std::cout << RED_COLOR;
							std::cout << " " << _piece->return_type() << " ";
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





bool Bord::play(Cord now, Cord after, bool iswhite) {
	if (!in_bounce(now)) { std::cout << "De plek waar hij staat is niet in bord";return false; }
	if (!in_bounce(after)) { std::cout << "De plek waar hij naartoe wil verplaatsen is niet in bord";return false; }
	for (Piece* piontomove : pieces)
	{
		if (compare_cord(now, piontomove->getcord())) {
			if (((piontomove->getcolor() == Color::W) && !iswhite)||(piontomove->getcolor()==Color::B && iswhite)){
				std::cout << "pion is niet van de juiste kleur";
				return false;
			}
			else if (piontomove->is_pos(now, after)) {
				bool gel = this->kill(after,iswhite);//altijd killen moest er iemand staan mag die weg
				if (gel) {
					piontomove->movepiece(after);
					return true;
				}
				else {
					std::cout << "je valt je eigen kleur aan";
					return false;
				}
			}
			else {
				std::cout << "geen mogelijke beweging";
				return false;
			}
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
	if (_cord.getcolum() > 8 || _cord.getcolum() < 0) { return false; }
	if (_cord.getrow() > 8 || _cord.getrow() < 0) { return false; }
	return true;
	}

bool Bord::kill(Cord to_kill,bool iswhite) {
	int tellerw = 0;
	for (Piece* _piece : pieces){
		if (compare_cord(_piece->getcord(), to_kill))
		{
			if ((_piece->getcolor() == Color::W && iswhite) || (_piece->getcolor() == Color::B && !iswhite)) {
				return false;
			}
			auto to_erase = std::find(pieces.begin(), pieces.end(), _piece);//find zoekt hier voor ons de juiste waarde om te erasen
			pieces.erase(to_erase);
			return true;
		}
	}
	return true;
}

int Bord::won() {
	bool white = true,black = true;
	for (Piece* piontocheck : pieces) {
		char what = piontocheck->return_type();
		if (what == 'K') {
			if (piontocheck->getcolor() == Color::W) { white = false; }
			else{ black = false; }
		}
	}
	if (black == false && white == true) { return 1; }
	else if (black == true && white == false) { return 2; }
	return 0;
}
void Bord::setplayer1(Player* a) {
	player1 = a;
}

void Bord::setplayer2(Player* b) {
	player2 = b;
}
Player* Bord::getplayer1() {
	return player1;
}
Player* Bord::getplayer2() {
	return player2;
}