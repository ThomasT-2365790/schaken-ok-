#include "Player.h"
#include "Color.h"
#include "Cord.h"
#include "Piece.h"

Player::Player(Color color) : _color{ color } {};

void Player::movestuk(Cord _now, Cord _new) {
	playbord.play(_now, _new);

}