#include "Queen.h"
#include <iostream>

bool Queen::is_pos(Cord _now, Cord _new) {
	if (_new.getcolum() == _now.getcolum() || _now.getrow() == _new.getrow()) {
		return true;
	}
	int dif_row = abs(_now.getrow() - _new.getrow());
	int dif_colum = abs(_now.getcolum() - _new.getcolum());
	if (dif_row == dif_colum) {
		return true;
	}
	return false;
}
Queen::Queen(Color kleur, Cord coord,Bord* spelbord) : Piece{ kleur, coord,spelbord } {};

char Queen::return_type()  {
	return 'Q';
}