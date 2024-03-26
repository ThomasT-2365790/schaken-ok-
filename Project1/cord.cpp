#include "cord.h"
#include "color.h"
Cord::Cord(int _rij, int _kolom) :rij{ _rij }, kolom{ _kolom } {}


void Cord::update_cord(int _kolom, int _rij)
{
	rij = _rij;
	kolom = _kolom;
}

int Cord::getkolom() {

	return kolom;
}
int Cord::getrij() {

	return rij;
}


