#include "Queen.h"
#include <iostream>

bool Queen::is_pos(Cord nu, Cord nieuw) {
	return true;
}
Queen::Queen(Color kleur, Cord coord) : Piece{ kleur, coord } {};

void Queen::print_type() const {
	std::cout << " Q ";
}