#include "Bishop.h"
#include <iostream>

bool Bishop::is_pos(Cord _now, Cord _new) {
	int dif_row = abs(_now.getrow() - _new.getrow());
	int dif_colum = abs(_now.getcolum() - _new.getcolum());
	if (dif_row == dif_colum) {
		return true;
	}
	return false;
}
Bishop::Bishop(Color kleur, Cord coord, Bord* spelbord) : Piece{ kleur, coord,spelbord } {};

char Bishop::return_type() {
	return 'B';
}