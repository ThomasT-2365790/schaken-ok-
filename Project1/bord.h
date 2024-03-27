#pragma once
#include <vector>
#include "Piece.h"
#include "Cord.h"
#include "Color.h"

class Bord {
	
public:
	Bord();
	void printbord();
	bool play(Cord now, Cord after,bool iswhite);
	Cord piece_at(Cord _cord);
	bool compare_cord(Cord one, Cord two);
	Color color_cord(Cord _cord);
	bool in_bounce(Cord _cord);
	bool kill(Cord to_kill,bool iswhite);
	int won();
private:
	std::vector <Piece*> pieces;
};
