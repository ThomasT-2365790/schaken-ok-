#include "Tower.h"
#include <iostream>

bool Tower::is_pos(Cord _now, Cord _new) {
	/*
	if (_new.getcolum() == _now.getcolum()) {
		return between_row();
	}
	if (_now.getrow() == _new.getrow()) {
		return between_colum();
	}
	return false;
	*/
	if (_new.getcolum() == _now.getcolum() || _now.getrow() == _new.getrow()) { return true; }
	return false;
}
/*
bool Tower::between_row(Cord _now, Cord _new) {
	int afstand = _new.getrow() - _now.getrow();
	if (afstand == 0) { return false; }
	if (afstand == -1 || afstand == 1) { return true; }
	if (afstand < -1) {
		while (afstand < -1) {
			afstand += 1;
			if (piece_at(Cord((_now.getrow() + afstand), _now.getcolum()) { return false; }
		}
		return true;
	}
	else {
		while (afstand > 1) {
			afstand -= 1;
			if (piece_at(Cord((_now.getrow() + afstand), _now.getcolum()) { return false; }
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
			if (piece_at(Cord (_new.getrow(),(_now.getcolum()+afstand)) { return false; }
		}
		return true;
	}
	else {
		while (afstand > 1) {
			afstand -= 1;
			if (piece_at(Cord (_new.getrow(),(_now.getcolum()+afstand)) { return false; }
		}
		return true;
	}
}*/

Tower::Tower(Color kleur, Cord coord) : Piece{ kleur, coord } {};

char Tower::return_type()  {
	return 'T';
}
/*
bool Tower::func_bord(Bord& bord,Cord cord) {
	if (bord.compare_cord(bord.piece_at(cord),Cord(0,0))) { return true; }
	return false;
}
*/