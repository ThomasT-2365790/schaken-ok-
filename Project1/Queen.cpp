#include "Queen.h"
#include <iostream>

bool Queen::is_pos(Cord nu, Cord nieuw) {
	return true;
}
Queen::Queen(Color kleur, Cord coord) : Piece{ kleur, coord } {};

char Queen::return_type()  {
	return 'Q';
}