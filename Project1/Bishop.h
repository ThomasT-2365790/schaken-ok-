#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Color color, Cord cord);
	bool is_pos(Cord _now, Cord _new);

private:

};