#pragma once
#include "Piece.h"
#include "bord.h"

class Tower : public Piece
{
public:
	Tower(Color color, Cord cord, Bord* spelbord);
	bool is_pos(Cord _now, Cord _new) override;
	char return_type()  override;
	bool between_row(Cord _now, Cord _new);
	bool between_colum(Cord _now, Cord _new);

private:

};