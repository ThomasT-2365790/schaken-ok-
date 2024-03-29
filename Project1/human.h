#pragma once
#include "Player.h"
#include "Color.h"
#include <tuple>
#include "Bord.h"
class Human : public Player {
public:
	Human(Color color,Bord* _bord);
	std::tuple<Cord,Cord> give_move() override;
	char give_gender() override;
private:

};