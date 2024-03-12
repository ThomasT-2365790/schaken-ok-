#include "pawn.h"

pawn::pawn(color kleur, cord coord) : stuk{ kleur,coord,what::PAWN } {
	mog_bew.push_back(cord(1, 0));

}

bool pawn::is_mog_bew(cord a)
{
	for (cord coord : mog_bew)
	{
		if ((a.getkolom() == coord.getkolom()) and (a.getrij() == coord.getrij()))
		{
			return true;
		}	
	}
	return false;

}