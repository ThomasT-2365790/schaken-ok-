#include "Bord.h"
#include "Player.h"
#include <iostream>
#include <string.h>
#include "Human.h"
#include "Bot.h"
#include "Cord.h"

std::string to_lower(std::string mode) {
	std::string solution{};
	for (char letter : mode) {
		if (letter < 'Z' - 1) {
			letter = tolower(letter);
		}
		solution += letter;
	}
	return solution;
}

int main() {
	Bord spelbord;

	bool correcteingave = false;

	Player* player=nullptr;
	Human _player1(Color::W,&spelbord);
	spelbord.setplayer1(&_player1);
	Human _player2_human(Color::B,&spelbord);
	Bot _player2_bot(Color::B,&spelbord);


	while (!correcteingave) {
		std::string gamemode;
		std::cout << "PvP or PvE\n";
		std::cin >> gamemode;
		gamemode = to_lower(gamemode);
		if (gamemode == "pvp") {
			spelbord.setplayer2(&_player2_human);
			correcteingave = true;
		}
		else if (gamemode=="pve") {
			spelbord.setplayer2(&_player2_bot);
			correcteingave = true;
		}
		else { std::cout << "geen mogelijke ingave, probeer opnieuw\n"; }
	}

	bool iswhite = true;
	while (true) {
		spelbord.printbord();

		if (iswhite) {
			std::cout << "White aan zet, wat wil je doen?\n";
			player=spelbord.getplayer1();
		}
		else {
			std::cout << "Black aan zet, wat wil je doen?\n";
			player =spelbord.getplayer2();
		}
		char gender = player->give_gender();
		bool suc;
		if (gender == 'H') {
			std::tuple<Cord, Cord> ingave = player->give_move();
			suc = spelbord.play_human(std::get<0>(ingave), std::get<1>(ingave), iswhite);
		}
		else {//Bot
			bool ready = false;
			int teller = 0;
			while(!ready) {
				std::tuple<Cord, Cord> ingave = player->give_move();
				ready = spelbord.play_bot(std::get<0>(ingave), std::get<1>(ingave), iswhite);
				++teller;

			}
			suc = true;
			std::cout << teller<<std::endl;
		}
		
		if (suc) { iswhite = !iswhite; }
		if (suc) {
			if (spelbord.won() == 1) { std::cout << "Zwart heeft gewonnen"; exit(0); }
			else if (spelbord.won() == 2) { std::cout << "Wit heeft gewonnen"; exit(0); }
		}
	}
	return 0;
}

