#include "cord.h"
#include <tuple>

cord::cord(int _kolom, int _rij) :rij{ _rij }, kolom{ _kolom } {}


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