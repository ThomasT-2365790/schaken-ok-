#include "pawn.h"
#include "bord.h"

bool Pawn::is_mog_bew(Cord nu,Cord nieuw) {

	if (nu.getkolom() == nieuw.getkolom())// moven zonder aanval
	{
		if (this->getcolor() == Color::W)/// W
		{
			if (nu.getrij() == 2)
			{
				if (nu.getrij() == nieuw.getrij() - 1 or nu.getrij() == nieuw.getrij() - 2){return true;}
			}
			else if (nu.getrij() == nieuw.getrij() - 1){return true;}
		}
		else///B
		{
			if (nu.getrij() == 7)
			{
				if (nu.getrij() == nieuw.getrij() + 1 or nu.getrij() == nieuw.getrij() + 2){return true;}
			}
			else if (nu.getrij() == nieuw.getrij() + 1){return true;}
		}
	}
	else if(nu.getkolom()==nieuw.getkolom()+1 or nu.getkolom()==nieuw.getkolom()-1)//aanval
	{
		if (this->getcolor() == Color::W and nu.getrij()==nieuw.getrij()-1)//W
		{
			if( spelbord.geefkleurvancoinbord(nieuw)==Color::B){ return true; }
			
		}
		else if (this->getcolor() == Color::B and nu.getrij() == nieuw.getrij() + 1)//B
		{
			if (spelbord.geefkleurvancoinbord(nieuw) == Color::W) { return true; }
		}
	}
	return false;//geen mog beweging

}
Pawn::Pawn(Color kleur, Cord coord) : Stuk{ kleur, coord } {
}