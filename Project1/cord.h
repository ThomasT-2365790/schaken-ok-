#pragma once
#include <tuple>
class cord {

public:
	cord(int _kolom, int _rij);
	void update_cord(int kolom, int rij);
	std::tuple<int,int> getcord();

private:
	int kolom;
	int rij;
};