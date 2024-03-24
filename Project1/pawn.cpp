#include "pawn.h"
#include "bord.h"

bool pawn::is_mog_bew(cord nu,cord nieuw) {

	if (nu.getkolom() == nieuw.getkolom())// moven zonder aanval
	{
		if (this->getcolor() == color::W)/// W
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
		if (this->getcolor() == color::W and nu.getrij()==nieuw.getrij()-1)//W
		{
			if( spelbord.geefkleurvancoinbord(nieuw)==color::W){ return true; }
			
		}
		else if (this->getcolor() == color::B and nu.getrij() == nieuw.getrij() + 1)//B
		{
			if (spelbord.geefkleurvancoinbord(nieuw) == color::B) { return true; }
		}
	}
	return false;//geen mog beweging

}
pawn::pawn(color kleur, cord coord) : stuk{ kleur, coord } {
}