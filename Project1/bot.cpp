#include "Bot.h"
#include "Color.h"
#include "Player.h"
#include <tuple>

Bot::Bot(Color color) : Player{ color } {};


std::tuple<Cord, Cord> Bot::give_move() {
	std::tuple<Cord, Cord> ingave{ Cord{0,0},Cord{0,0} };
	return ingave;
}