#pragma once
#include "Piece.h"
#include <string>

class Bishop : public Piece
{
public:
	Bishop(Color color, Cord cord, Bord* spelbord);
	bool is_pos(Cord _now, Cord _new) override;
	char return_type()  override;
	std::string to_where(Cord _now, Cord _new);
	bool viewer_between(Cord _now,  int rij, int kolom,int verschil);

private:

};