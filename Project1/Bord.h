#pragma once
#include <vector>
#include "Piece.h"
#include "Cord.h"
#include "Color.h"

class Bord {
	
public:
	Bord();
	void printbord();
	void setpiece(Piece _piece);
	void play(Cord now, Cord after);
	Cord piece_at(Cord _cord);
	bool compare_cord(Cord one, Cord two);
	Color color_cord(Cord _cord);
	bool in_bounce(Cord _cord);
	void kill(Cord to_kill);
private:
	std::vector <Piece*> pieces;
};
