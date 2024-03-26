#pragma once
class Cord {

public:
	Cord(int _row, int _colum);
	void update_cord(int _row, int _colum);
	int getcolum();
	int getrow();
	

	friend class Bord;//niet in uml

private:
	int row;
	int colum;
};