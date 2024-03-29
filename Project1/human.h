#pragma once
#include "Player.h"
#include "Color.h"
#include <tuple>
class Human : public Player {
public:
	Human(Color color);
	std::tuple<Cord,Cord> give_move() override;
	char give_gender() override;
private:

};