#pragma once
#include "Cord.h"
#include "Color.h"
class Player {

public:
	Player(Color _color);
	void movepiece(Cord _now, Cord _new);

private:
	Color _color;

};