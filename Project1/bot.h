#pragma once
#include "Player.h"
class Bot : public Player {

public:
	Bot(Color color);
	std::tuple<Cord,Cord> give_move() override;
	char give_gender() override;

private:

};