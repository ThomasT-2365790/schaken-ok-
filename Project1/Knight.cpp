#include "Knight.h"
#include <math.h>
#include <iostream>

bool Knight::is_pos(Cord _now, Cord _new) {
	int dif_row = abs(_now.getrow() - _new.getrow());
	int dif_colum = abs(_now.getcolum() - _new.getcolum());
	if ((dif_colum == 1 && dif_row == 2) || (dif_colum == 2 && dif_row == 1)) {
		return true;
	}
	return false;
}
Knight::Knight(Color kleur, Cord coord, Bord* spelbord) : Piece{ kleur, coord,spelbord } {};

char Knight::return_type()  {
	return 'k';
}