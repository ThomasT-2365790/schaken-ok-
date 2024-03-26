#include "Bord.h"
#include "Player.h"
#include <iostream>
#include <string.h>
#include "Human.h"
#include "Bot.h"

int main() {
	Bord spelbord;
	spelbord.printbord();

	std::string gamemode;
	std::cout << "PvP or PvE";
	std::cin >> gamemode;
	Human player1(Color::W);
	if (gamemode == "PvP"){
		Human player2(Color::B);
	}
	else if (gamemode == "PvE") {
		Bot player2(Color::B);
	}


	bool iswhite = true;
	
	while (true) {
		





		iswhite = !iswhite;
	}
	return 0;
}