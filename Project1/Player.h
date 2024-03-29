#pragma once
#include "Cord.h"
#include "Color.h"
#include <string>

class Player {

public:
	Player(Color _color,Bord* _bord);
	virtual std::tuple<Cord,Cord> give_move();
	virtual char give_gender();
	Cord give__piece();

private:
	Color _color;
	Bord* spelbord;

};