#include "bord.h"
#include "speler.h"
#include <iostream>
#include <string.h>
#include "human.h"
#include "bot.h"

int main() {
	bord spelbord;
	

	std::string gamemode;
	std::cout << "PvP or PvE";
	std::cin >> gamemode;
	human player1(color::W);
	if (gamemode == "PvP"){
		human player2(color::B);
	}
	else if (gamemode == "PvE") {
		bot player2(color::B);
	}


	bool iswhite = true;
	while (true) {
		





		iswhite = !iswhite;
	}
	return 0;
}