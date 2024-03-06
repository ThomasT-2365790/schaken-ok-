#include "cord.h"
#include <tuple>

cord::cord(int _kolom, int _rij) :cordinaat{_kolom,_rij} {}


void cord::update_cord(int _kolom, int _rij)
{
	cordinaat = { _kolom,_rij };
}

std::tuple<int,int> cord::getcord() {

	return cordinaat;

}