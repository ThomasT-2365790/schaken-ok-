#pragma once
#include "Player.h"
#include "Bord.h"
class Bot : public Player {

public:
	Bot(Color color,Bord* _bord);
	std::tuple<Cord,Cord> give_move() override;
	char give_gender() override;

private:

};