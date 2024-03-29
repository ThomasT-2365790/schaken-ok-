#include "Player.h"
#include "Color.h"
#include "Cord.h"
#include "Piece.h"
#include <tuple>

Player::Player(Color color) : _color{ color } {};

std::tuple<Cord,Cord> Player::give_move() {
	std::tuple<Cord, Cord> ingave{ Cord{0,0},Cord{0,0} };
	return ingave;
}

char Player::give_gender() {
	return ' ';
}