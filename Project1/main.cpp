#include "bord.h"
#include <iostream>

int main() {
	std::cout << "startspel\n";
	bord spelbord;
	while (true)
	{
		spelbord.printbord();
		int xnu;
		int ynu;
		int xnieuw;
		int ynieuw;
		std::cout << "van: ";
		std::cin >> xnu>> ynu;
		cord nu{ xnu,ynu };
		std::cout << "naar: ";
		std::cin >> xnieuw >> ynieuw;
		cord nieuw{ xnieuw,ynieuw };
		spelbord.play(nu, nieuw);
	}
	
	

	spelbord.printbord();
	return 0;
}