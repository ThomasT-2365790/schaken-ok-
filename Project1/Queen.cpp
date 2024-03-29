#include "Queen.h"
#include <iostream>

bool Queen::between_row(Cord _now, Cord _new) {
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
bool Queen::between_colum(Cord _now, Cord _new) {
	int afstand = _new.getcolum() - _now.getcolum();
	if (afstand == 0) { return false; }
	if (afstand == -1 || afstand == 1) { return true; }
	if (afstand < -1) {
		while (afstand < -1) {
			afstand += 1;
			if (is_piece_at(Cord(_new.getrow(), (_now.getcolum() + afstand)))) { return false; }
		}
		return true;
	}
	else {
		while (afstand > 1) {
			afstand -= 1;
			if (is_piece_at(Cord(_new.getrow(), (_now.getcolum() + afstand)))) { return false; }
		}
		return true;
	}
}

std::string Queen::to_where(Cord _now, Cord _new) {
	if (_now.getrow() > _new.getrow() && _now.getcolum() > _new.getcolum()) { return std::string{ "leftunder" }; }
	else if (_now.getrow() > _new.getrow() && _now.getcolum() < _new.getcolum()) { return std::string{ "rightunder" }; }
	else if (_now.getrow() < _new.getrow() && _now.getcolum() > _new.getcolum()) { return std::string{ "lefttupper" }; }
	else if (_now.getrow() < _new.getrow() && _now.getcolum() < _new.getcolum()) { return std::string{ "rightupper" }; }
	else { return std::string{ "kan sowieso niet, loopt mis bij dif==dif" }; }
}

bool Queen::viewer_between(Cord _now, int row, int colum, int difference) {
	for (int index = 1;index < difference;++index) {
		if (is_piece_at(Cord(_now.getrow() + index * row, _now.getcolum() + index * colum))) {
			return false;
		}
	}
	return true;
}

bool Queen::is_pos(Cord _now, Cord _new) {
	if (_new.getcolum() == _now.getcolum()) {
		return between_row(_now, _new);
	}
	if (_now.getrow() == _new.getrow()) {
		return between_colum(_now, _new);
	}
	std::string where = to_where(_now, _new);
	int dif_row = abs(_now.getrow() - _new.getrow());
	int dif_colum = abs(_now.getcolum() - _new.getcolum());
	if (dif_row == dif_colum) {
		if (where == "leftunder" && viewer_between(_now, -1, -1, dif_row)) { return true; }
		else if (where == "rightunder" && viewer_between(_now, -1, +1, dif_row)) { return true; }
		else if (where == "leftupper" && viewer_between(_now, +1, -1, dif_row)) { return true; }
		else if (where == "rightupper" && viewer_between(_now, +1, +1, dif_row)) { return true; }
		else { return false; }
	}
	else {
		return false;
	}
	
}
Queen::Queen(Color kleur, Cord coord,Bord* spelbord) : Piece{ kleur, coord,spelbord } {};

char Queen::return_type()  {
	return 'Q';
}