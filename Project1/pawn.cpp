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
				if (nu.getrow() == nieuw.getrow() - 1 or nu.getrow() == nieuw.getrow() - 2){return true;}
			}
			else if (nu.getrow() == nieuw.getrow() - 1){return true;}
		}
		else///B
		{
			if (nu.getrow() == 7)
			{
				if (nu.getrow() == nieuw.getrow() + 1 or nu.getrow() == nieuw.getrow() + 2){return true;}
			}
			else if (nu.getrow() == nieuw.getrow() + 1){return true;}
		}
	}
	else if(nu.getcolum()==nieuw.getcolum()+1 or nu.getcolum()==nieuw.getcolum()-1)//aanval
	{
		if (this->getcolor() == Color::W and nu.getrow()==nieuw.getrow()-1)//W
		{
			if( this->getcolor() == Color::B) { return true; }
			
		}
		else if (this->getcolor() == Color::B and nu.getrow() == nieuw.getrow() + 1)//B
		{
			if (this->getcolor() == Color::W) { return true; }
		}
	}
	return false;//geen mog beweging

}
Pawn::Pawn(Color kleur, Cord coord) : Piece{ kleur, coord } {};

void Pawn::print_type() const {
	std::cout << " P ";
}
