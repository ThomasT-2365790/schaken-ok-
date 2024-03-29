#pragma once
#include "Piece.h"
#include <string>

class Queen : public Piece
{
public:
	Queen(Color color, Cord cord, Bord* spelbord);
	bool is_pos(Cord _now, Cord _new) override;
	char return_type()  override;
	bool between_row(Cord _now, Cord _new);//from tower
	bool between_colum(Cord _now, Cord _new);//from tower
	std::string to_where(Cord _now, Cord _new);//from Bishop
	bool viewer_between(Cord _now, int rij, int kolom, int verschil);//from Bishop

private:

};