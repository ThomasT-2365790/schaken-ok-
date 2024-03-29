#include "Bot.h"
#include "Color.h"
#include "Player.h"
#include <tuple>
#include <cstdlib>
#include <ctime>
#include "Bord.h"

Bot::Bot(Color color,Bord* _bord) : Player{ color,_bord } {};


std::tuple<Cord, Cord> Bot::give_move() {
	srand(time(0));
	Cord staatstuk = give__piece();
	std::tuple<Cord, Cord> ingave{ staatstuk,Cord{(rand() % 8)+1 ,(rand() % 8)+1 } };
	return ingave;
}

char Bot::give_gender() {
	return 'B';
}