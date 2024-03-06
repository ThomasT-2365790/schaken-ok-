#pragma once
class cord {

public:
	cord(int _kolom, int _rij);
	void update_cord(int kolom, int rij);
	int getkolom();
	int getrij();

private:
	int kolom;
	int rij;
};