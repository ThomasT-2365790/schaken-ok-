#pragma once
#include "Cord.h"
#include "Color.h"
#include <vector>
class Bord;//in de plaats van includen, als ik include infinte loop

class Piece {

public:
	Piece(Color kleur, Cord coord); //constructor
	Color getcolor();
	void movepiece(Cord& nieuw);
	Cord getcord();
	bool compare_cord(Cord one, Cord two);
	virtual void print_type();

private:
	Color color_piece;
	Cord cordinate;


	

};