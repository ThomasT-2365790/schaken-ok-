#include "Player.h"
#include "Color.h"
#include "Cord.h"
#include "Piece.h"
#include <tuple>
#include "Bord.h"

Player::Player(Color color, Bord* _bord) : _color{ color }, spelbord{ _bord } {};

std::tuple<Cord,Cord> Player::give_move() {
	std::tuple<Cord, Cord> ingave{ Cord{0,0},Cord{0,0} };
	return ingave;
}

char Player::give_gender() {
	return ' ';
}
Cord Player::give__piece() {
	Cord opl= spelbord->give_piece();
		return opl;
}