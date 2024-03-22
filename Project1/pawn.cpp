#include "pawn.h"
#include "bord.h"

bool pawn::is_mog_bew(cord nu,cord nieuw) {

	if (nu.getkolom() == nieuw.getkolom())// moven zonder aanval
	{
		if (this->getcolor() == color::W)
		{
			if (nu.getrij() == 2)
			{
				if (nu.getrij() == nieuw.getrij() - 1 or nu.getrij() == nieuw.getrij() - 2){return true;}
			}
			else if (nu.getrij() == nieuw.getrij() - 1){return true;}
		}
		else
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
		if (this->getcolor() == color::W and nu.getrij()==nieuw.getrij()-1)
		{
			if (naam->isPionAt() { return true; }
			
		}
		else if (this->getcolor() == color::B and nu.getrij() == nieuw.getrij() + 1)
		{
			if (1 == 1) { return true; }
		}
	}
	return false;

}
pawn::pawn(color kleur, cord coord) : stuk{ kleur, coord } {
}