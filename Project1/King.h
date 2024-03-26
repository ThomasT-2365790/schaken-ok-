#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Color color, Cord cord);
	bool is_pos(Cord _now, Cord _new);

private:

};