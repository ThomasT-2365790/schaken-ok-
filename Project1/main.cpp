#include "bord.h"
#include <iostream>

int main() {
	bord spelbord;
	spelbord.printbord();
	std::cout << std::endl;
	spelbord.playw(cord(2, 1), cord(5, 5));

	spelbord.printbord();
	return 0;
}