#pragma once
class cord {

public:
	cord(int _rij, int _kolom);
	void update_cord(int rij, int kolom);
	int getkolom();
	int getrij();

private:
	int rij;
	int kolom;
};