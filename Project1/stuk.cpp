#include "stuk.h"
#include "color.h"
#include <iostream>
#include "what.h"

stuk::stuk(color kleur, cord coord, what gender) :collor{ kleur }, coordinaat{ coord },wat{ gender } {
	switch (gender)
	{
	case what::PAWN:
	{
		bew_pawn.push_back(cord(1, 0));
	}




	}


}
bool stuk::is_mog_bew(cord verschil,cord nu)
{
	switch (getwhat(nu))
	{
	case what::PAWN:
	{
		for (cord plek : bew_pawn)
		{
			if (coordinaatvergelijker_stuk(verschil, plek)) {
				return true;
			}
		}
		return false;
	}




	}
}

color stuk::getcolor()
{
	return collor;
}

void stuk::movestuk(cord& nieuw)
{
	coordinaat = nieuw;
}

cord stuk::getcord()
{
	return coordinaat;
}

what stuk::getwhat() {
	return wat;
}
bool stuk::coordinaatvergelijker_stuk(cord a, cord b)
{
	if ((a.getkolom() == b.getkolom()) and (a.getrij() == b.getrij()))
	{
		return true;
	}
	return false;