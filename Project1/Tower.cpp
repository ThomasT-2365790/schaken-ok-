#include "Tower.h"

bool Tower::is_pos(Cord _now, Cord _new) {
	if (_new.getcolum() == _now.getcolum() || _now.getrow() == _new.getrow()) {
		return true;
	}
	return false;
}
Tower::Tower(Color kleur, Cord coord) : Piece{ kleur, coord } {};