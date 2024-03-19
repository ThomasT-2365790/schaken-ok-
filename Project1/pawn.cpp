#include "pawn.h"

bool pawn::is_mog_bew(cord coord) {

	for (cord mog : bew_pawn)
	{
		if (coordinaatvergelijker_stuk(mog, coord))
		{
			return true;
		}
		return false;
	}

}
pawn::pawn(color kleur, cord coord) : stuk{ kleur, coord, what::PAWN } {
	bew_pawn.push_back(cord(1, 0));
}