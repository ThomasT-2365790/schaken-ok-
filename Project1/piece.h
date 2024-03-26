#pragma once
#include "Cord.h"
#include "Color.h"
#include <vector>
#include "Bord.h"

class Piece {

public:
	Piece(Color kleur, Cord coord); //constructor
	Color getcolor();
	void movepiece(Cord& nieuw);
	Cord getcord();
	bool compare_cord(Cord one, Cord two);

private:
	Color color_piece;
	Cord cordinate;
protected:
	Bord& playbord;

	

};