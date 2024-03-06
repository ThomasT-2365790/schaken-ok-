#include "bord.h"
#include <iostream>

void main() {
	bord spelbord;
	spelbord.printbord();
	std::cout << std::endl;
	spelbord.playw(cord(1, 2), cord(5, 5));

	spelbord.printbord();
}