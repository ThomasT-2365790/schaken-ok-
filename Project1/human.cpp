#include "human.h"
#include <iostream>
#include <tuple>
#include "Cord.h"

Human::Human(Color kleur) :Player{ kleur } {};


int char_to_int(char a) {
	int b =tolower(a);
	return (b-96);
}



std::tuple<Cord,Cord> Human::give_move() {

	char rij_van_char, rij_naar_char;
	int	kolom_van, kolom_naar;
	std::cin >> rij_van_char >> kolom_van >> rij_naar_char >> kolom_naar;

	int rij_van = char_to_int(rij_van_char);
	int rij_naar = char_to_int(rij_naar_char);
	Cord _now(kolom_van, rij_van);
	Cord _new(kolom_naar, rij_naar);
	std::tuple<Cord, Cord> inputtuple{ _now,_new };
	return inputtuple;
}

char Human::give_gender() {
	return 'H';
}