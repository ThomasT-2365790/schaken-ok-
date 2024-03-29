#include "Bot.h"
#include "Color.h"
#include "Player.h"
#include <tuple>
#include <cstdlib>
#include <ctime>

Bot::Bot(Color color) : Player{ color } {};


std::tuple<Cord, Cord> Bot::give_move() {
	srand(time(0));
	std::tuple<Cord, Cord> ingave{ Cord{rand() % 8 + 1,rand() % 8 + 1},Cord{rand() % 8 + 1,rand() % 8 + 1} };
	return ingave;
}

char Bot::give_gender() {
	return 'B';
}