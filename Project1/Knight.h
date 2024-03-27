#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Color color, Cord cord);
	bool is_pos(Cord _now, Cord _new) override;
	char return_type()  override;

private:

};