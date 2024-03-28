#include "Tower.h"
#include <iostream>

bool Tower::is_pos(Cord _now, Cord _new) {
	if (_new.getcolum() == _now.getcolum()) {
		return between_row(_now,_new);
	}
	if (_now.getrow() == _new.getrow()) {
		return between_colum(_now,_new);
	}
	return false;
}
bool Tower::between_row(Cord _now, Cord _new) {
	int afstand = _new.getrow() - _now.getrow();
	if (afstand == 0) { return false; }
	if (afstand == -1 || afstand == 1) { return true; }
	if (afstand < -1) {
		while (afstand < -1) {
			afstand += 1;
			if (is_piece_at(Cord((_now.getrow() + afstand), _now.getcolum()))) { return false; }
		}
		return true;
	}
	else {
		while (afstand > 1) {
			afstand -= 1;
			if (is_piece_at(Cord((_now.getrow() + afstand), _now.getcolum()))) { return false; }
		}
		return true;
	}
}
bool Tower::between_colum(Cord _now, Cord _new) {
	int afstand = _new.getcolum() - _now.getcolum();
	if (afstand == 0) { return false; }
	if (afstand == -1 || afstand == 1) { return true; }
	if (afstand < -1) {
		while (afstand < -1) {
			afstand += 1;
			if (is_piece_at(Cord (_new.getrow(),(_now.getcolum()+afstand)))) { return false; }
		}
		return true;
	}
	else {
		while (afstand > 1) {
			afstand -= 1;
			if (is_piece_at(Cord (_new.getrow(),(_now.getcolum()+afstand)))) { return false; }
		}
		return true;
	}
}

Tower::Tower(Color kleur, Cord coord,Bord* _bord) : Piece{ kleur, coord,_bord } {};

char Tower::return_type()  {
	return 'T';
}