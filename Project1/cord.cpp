#include "cord.h"
#include "what.h"

cord::cord(int _rij, int _kolom) :rij{ _rij }, kolom{ _kolom } {}


void cord::update_cord(int _kolom, int _rij)
{
	rij = _rij;
	kolom = _kolom;
}

int cord::getkolom() {

	return kolom;
}
int cord::getrij() {

	return rij;
}

