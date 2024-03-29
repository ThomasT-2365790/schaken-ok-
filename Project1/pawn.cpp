#include "Pawn.h"
#include "Bord.h"
#include <iostream>

bool Pawn::is_pos(Cord nu,Cord nieuw) {

	if (nu.getcolum() == nieuw.getcolum())// moven zonder aanval
	{
		if (this->getcolor() == Color::W)/// W
		{
			if (nu.getrow() == 2)
			{
				if (nu.getrow() == nieuw.getrow() - 1 || nu.getrow() == nieuw.getrow() - 2){return true;}
			}
			else if (nu.getrow() == nieuw.getrow() - 1){return true;}
		}
		else///B
		{
			if (nu.getrow() == 7)
			{
				if (nu.getrow() == nieuw.getrow() + 1 || nu.getrow() == nieuw.getrow() + 2){return true;}
			}
			else if (nu.getrow() == nieuw.getrow() + 1){return true;}
		}
	}
	else if(nu.getcolum()==nieuw.getcolum()+1 || nu.getcolum()==nieuw.getcolum()-1)//aanval
	{
		if (this->getcolor() == Color::W && nu.getrow()==nieuw.getrow()-1)//W
		{
			if (is_piece_at(nieuw)) { return true; }
			
		}
		else if (this->getcolor() == Color::B && nu.getrow() == nieuw.getrow() + 1)//B
		{
			if (is_piece_at(nieuw)) { return true; }
		}
	}
	return false;//geen mog beweging

}
Pawn::Pawn(Color kleur, Cord coord,Bord* spelbord) : Piece{ kleur, coord,spelbord } {};

char Pawn::return_type()  {
	return 'P';
}

