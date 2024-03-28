#include "Bord.h"
#include "Player.h"
#include <iostream>
#include <string.h>
#include "Human.h"
#include "Bot.h"


int char_to_int(char a) {
	int b =tolower(a);
	return (b-96);
}


int main() {
	Bord spelbord;

	bool correcteingave = false;

	Player* player=nullptr;
	Player* player1=nullptr;
	Player* player2=nullptr;

	while (!correcteingave) {
	std::string gamemode;
	std::cout << "PvP or PvE\n";
	std::cin >> gamemode;

	Human _player1(Color::W);
	player1 = &_player1;

	if (gamemode == "PvP") {
		Human _player2(Color::B);
		player2 = &_player2;
		correcteingave = true;
	}
	else if (gamemode=="PvE") {
		Bot _player2(Color::B);
		player2 = &_player2;
		correcteingave = true;
	}
	else { std::cout << "geen mogelijke ingave, probeer opnieuw\n"; }
	}
	bool iswhite = true;
	while (true) {
		spelbord.printbord();

		char rij_van_char, rij_naar_char;
		int kolom_van, kolom_naar;
		if (iswhite) {
			std::cout << "White aan zet, wat wil je doen?\n";
			Player* player=player1;
		}
		else {
			std::cout << "Black aan zet, wat wil je doen?\n";
			Player* player =player2;
		}
		std::cin >> rij_van_char >> kolom_van >> rij_naar_char >> kolom_naar;
		int rij_van = char_to_int(rij_van_char);
		int rij_naar = char_to_int(rij_naar_char);
		Cord _now(kolom_van, rij_van);
		Cord _new(kolom_naar, rij_naar);

		bool suc = spelbord.play(_now,_new,iswhite);
		
		if (suc) { iswhite = !iswhite; }
		if (suc) {
			if (spelbord.won() == 1) { std::cout << "Zwart heeft gewonnen"; exit(0); }
			else if (spelbord.won() == 2) { std::cout << "Wit heeft gewonnen"; exit(0); }
		}
	}
	return 0;
}

