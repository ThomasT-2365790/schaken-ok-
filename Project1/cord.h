#pragma once
class cord {

public:
	cord(int _rij, int _kolom);
	void update_cord(int rij, int kolom);
	int getkolom();
	int getrij();
	void setcord(cord other);

	friend class bord;

private:
	int rij;
	int kolom;
};