#include "Piece.h"
#include "Color.h"
#include <iostream>

Piece::Piece(Color _color, Cord _cord) :color_piece{ _color }, cordinate{ _cord } {};


Color Piece::getcolor()
{
	return color_piece;
}

void Piece::movepiece(Cord& nieuw)
{
	cordinate = nieuw;
}

Cord Piece::getcord()
{
	return cordinate;
}

bool Piece::compare_cord(Cord a, Cord b)
{
	if ((a.getcolum() == b.getcolum()) and (a.getrow() == b.getrow()))
	{
		return true;
	}
	return false;
}

void Piece::print_type() const {

	std::cout << " Piece ";
}

