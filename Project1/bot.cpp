#include "Bot.h"
#include "Color.h"
#include "Player.h"

Bot::Bot(Color color) : Player{ color } {};


bool Bot::automove() {
	return true;

}