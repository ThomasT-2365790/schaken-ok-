#pragma once
#include "Cord.h"
#include "Color.h"
#include <vector>
class Bord;//in de plaats van includen, als ik include infinte loop

class Piece {

public:
	Piece(Color kleur, Cord coord,Bord* _spelbord); //constructor
	Color getcolor();
	void movepiece(Cord& nieuw);// deze moved gewoon geen controles
	Cord getcord();
	virtual char return_type();
	virtual bool is_pos(Cord _now, Cord _new);
	bool is_piece_at(Cord _cord);

private:
	Color color_piece;
	Cord cordinate;
	Bord* spelbord;


	

};