#include "cord.h"
#include <tuple>

cord::cord(int _kolom, int _rij) :kolom{ _kolom }, rij{ _rij } {}


void cord::update_cord(int _kolom, int _rij)
{
	kolom = _kolom;
	rij = _rij;
}

std::tuple cord::getcord() {

	return std::tuple(kolom, rij)

}