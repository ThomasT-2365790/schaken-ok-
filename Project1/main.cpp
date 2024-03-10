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
    int teller_kleur = 0;
	while (teller_kleur<100)
	{
		spelbord.printbord();
		char letternu;
		int cijfernu;
		char letternieuw;
		int cijfernieuw;

        if (teller_kleur % 2 == 0)
        {
            std::cout << "play white\n";
        }
        else
        {
            std::cout << "play black\n";
        }
		std::cout << "van: ";
		std::cin >> letternu>> cijfernu;
		int lettergoednu =char_to_int(letternu);
		cord nu{ cijfernu,lettergoednu };
        if (spelbord.geefkleurvanco(nu) == color::W)
        {
            if (teller_kleur % 2 != 0)
                std::cout << "opnieuw, black is aan de beurt\n";
                break;
        }
        if (spelbord.geefkleurvanco(nu) == color::B)
        {
            if (teller_kleur % 2 == 0)
                std::cout << "opnieuw, white is aan de beurt\n";
            break;
        }

		std::cout << "naar: ";
		std::cin >> letternieuw >> cijfernieuw;
		int lettergoednieuw = char_to_int(letternieuw);
		cord nieuw{ cijfernieuw,lettergoednieuw };

		spelbord.play(nu, nieuw);
        ++teller_kleur;

	}
	
	

	spelbord.printbord();
	return 0;
}

