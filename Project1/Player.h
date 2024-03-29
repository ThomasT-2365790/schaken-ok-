#pragma once
#include "Cord.h"
#include "Color.h"
#include <string>
class Player {

public:
	Player(Color _color);
	virtual std::tuple<Cord,Cord> give_move();
	virtual char give_gender();

private:
	Color _color;

};