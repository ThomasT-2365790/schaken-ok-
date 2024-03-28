#pragma once
#include "Cord.h"
#include "Color.h"
#include <string>
class Player {

public:
	Player(Color _color);
	virtual std::tuple<Cord,Cord> give_move();

private:
	Color _color;

};