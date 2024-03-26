#pragma once
#include "Piece.h"

class Tower : public Piece
{
public:
	Tower(Color color, Cord cord);
	bool is_pos(Cord _now, Cord _new);
	void print_type()  override;

private:

};