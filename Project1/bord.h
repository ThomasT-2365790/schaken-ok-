#pragma once
#include <vector>
#include "Piece.h"
#include "Cord.h"
#include "Color.h"
#include "Player.h"

class Bord {
	
public:
	Bord();
	void printbord();
	bool play(Cord now, Cord after,bool iswhite);
	Cord piece_at(Cord _cord);
	bool compare_cord(Cord one, Cord two);
	bool in_bounce(Cord _cord);
	bool kill(Cord to_kill,bool iswhite);
	int won();

	void setplayer1(Player* _player);
	void setplayer2(Player* _player);
	Player* getplayer1();
	Player* getplayer2();
private:
	std::vector <Piece*> pieces;
	Player* player1;
	Player* player2;
};
