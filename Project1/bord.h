#pragma once
#include <vector>
#include "Piece.h"
#include "Cord.h"
#include "Color.h"

class Bord {
	
public:
	Bord();
	void printbord();
	void setpiece(Piece piece);
	void play(Cord now, Cord after);
	Cord piece_at(Cord _cord);
	bool compare_cord(Cord one, Cord two);
	Color color_cord(Cord coord);
	bool in_bounce(Cord coord);
	void kill(Cord to_kill);
private:
	std::vector <Piece*> Pieces;
};
