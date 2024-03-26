#include "King.h"
#include <math.h>

bool King::is_pos(Cord _now, Cord _new) {
	int dif_row = abs(_now.getrow() - _new.getrow());
	int dif_colum = abs(_now.getcolum() - _new.getcolum());
	if ((dif_row == 1 || dif_row == 0) && (dif_colum == 1 || dif_colum == 0) && !(dif_row == 0 && dif_colum == 0)) {
		return true;
	}
	return false;
}
King::King(Color kleur, Cord coord) : Piece{ kleur, coord } {};