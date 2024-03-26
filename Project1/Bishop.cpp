#include "Bishop.h"
#include <iostream>

bool Bishop::is_pos(Cord _now, Cord _new) {
	
	return false;
}
Bishop::Bishop(Color kleur, Cord coord) : Piece{ kleur, coord } {};

void Bishop::print_type() const {
	std::cout << " B ";
}