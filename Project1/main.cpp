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
        if (cijfernu<0 or cijfernu>8)
        {
            std::cout << "niet in de juiste rij!\n";
            continue;
        }
        if (lettergoednu < 0 or lettergoednu>8)
        {
            std::cout << "niet in de juiste kolom!\n";
            continue;
        }
        if (spelbord.coordinaatvergelijker_inbord(spelbord.isPionAt(nu), cord(0, 0)))
        {
            std::cout << "hier staat geen stuk!\n";
            continue;
        }
        if (spelbord.geefkleurvanco(nu) == color::W)
        {
            if (teller_kleur % 2 != 0)
            {
                std::cout << "opnieuw, black is aan de beurt\n";
                continue;
            }
        }
        if (spelbord.geefkleurvanco(nu) == color::B)
        {
            if (teller_kleur % 2 == 0)
            {
            
            std::cout << "opnieuw, white is aan de beurt\n";
            continue;
            }
        }
       

		std::cout << "naar: ";
		std::cin >> letternieuw >> cijfernieuw;
		int lettergoednieuw = char_to_int(letternieuw);
		cord nieuw{ cijfernieuw,lettergoednieuw };
        if (cijfernieuw < 0 or cijfernieuw>8)
        {
            std::cout << "niet in de juiste rij!\n";
            continue;
        }
        if (lettergoednieuw < 0 or lettergoednieuw>8)
        {
            std::cout << "niet in de juiste kolom!\n";
            continue;
        }

		spelbord.play(nu, nieuw);
        ++teller_kleur;

	}
	
	

	spelbord.printbord();
	return 0;
}

