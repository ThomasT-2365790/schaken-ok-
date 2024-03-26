#include "Cord.h"
#include "Color.h"
Cord::Cord(int _row, int _colum) :row{ _row }, colum{ _colum } {}


void Cord::update_cord(int _row, int _colum)
{
	row = _row;
	colum = _colum;
}

int Cord::getcolum() {

	return colum;
}
int Cord::getrow() {

	return row;
}


