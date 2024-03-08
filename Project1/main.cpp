#include "bord.h"
#include <iostream>
int char_to_int(char letter)
{
    int num;
    switch (letter) {
    case 'A':
        num = 1;
        break;
    case 'B':
        num = 2;
        break;
    case 'C':
        num = 3;
        break;
    case 'D':
        num = 4;
        break;
    case 'E':
        num = 5;
        break;
    case 'F':
        num = 6;
        break;
    case 'G':
        num = 7;
        break;
    case 'H':
        num = 8;
        break;
    default:
        std::cout << "Ongeldige invoer!";
        return 1;
        
    }
    return num;
}


int main() {
	std::cout << "startspel\n";
	bord spelbord;
	while (true)
	{
		spelbord.printbord();
		char letternu;
		int cijfernu;
		char letternieuw;
		int cijfernieuw;

		std::cout << "van: ";
		std::cin >> letternu>> cijfernu;
		int lettergoednu =char_to_int(letternu);
		cord nu{ cijfernu,lettergoednu };

		std::cout << "naar: ";
		std::cin >> letternieuw >> cijfernieuw;
		int lettergoednieuw = char_to_int(letternieuw);
		cord nieuw{ cijfernieuw,lettergoednieuw };

		spelbord.play(nu, nieuw);
	}
	
	

	spelbord.printbord();
	return 0;
}

