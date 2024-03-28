#include "Piece.h"
#include "Color.h"
#include <iostream>
#include "bord.h"

Piece::Piece(Color _color, Cord _cord, Bord* _spelbord) :color_piece{ _color }, cordinate{ _cord }, spelbord{ _spelbord } {};


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
char Piece::return_type() {

	return' ';
}
bool Piece::is_pos(Cord _now, Cord _new) {
	return true;
}
bool Piece::is_piece_at(Cord _cord) {
	Cord ontvangen = spelbord->piece_at(_cord);
	if (spelbord->compare_cord(ontvangen, _cord)) { return true; }
	return false;
}

