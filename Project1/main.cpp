#include "bord.h"
#include "pawn.h"
#include <iostream>
int char_to_int(char letter)//deze zet de letterinvoer van de user om naar een cijfer
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
        return 9;
        
    }
    return num;
}

cord verschil_coordwhite(cord a, cord b) {      //deze berekent het verschil tussen 2 coordinaten
    int kolom = b.getkolom() - a.getkolom();
    int rij = b.getrij() - a.getrij();
    return cord(rij, kolom);
}
cord verschil_coordblack(cord a, cord b) {      //deze berekent het verschil tussen 2 coordinaten
    int kolom = a.getkolom() - b.getkolom();
    int rij = a.getrij() - b.getrij();
    return cord(rij, kolom);
}

int main() {
    std::cout << "startspel\n";
    bord spelbord;
    int teller_kleur = 0;

    while (teller_kleur < 100)
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
        if (!(std::cin >> letternu >> cijfernu)) {
            std::cout << "Ongeldige invoer!\n";
            std::cin.clear(); // Clear foutstatus van std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Negeer de rest van de invoerregel
            continue;
        }
        int lettergoednu = char_to_int(letternu);


        cord nu{ cijfernu,lettergoednu };
        if (cijfernu < 0 or cijfernu>8)
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

        if (!(std::cin >> letternieuw >> cijfernieuw)) {
            std::cout << "Ongeldige invoer!\n";
            std::cin.clear(); // Clear foutstatus van std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Negeer de rest van de invoerregel
            continue;
        }
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
            cord verschil(0,0);
            if (teller_kleur % 2 == 0) {
                verschil = verschil_coordwhite(nu, nieuw);
            }
            if (teller_kleur % 2 != 0)
                {
                verschil = verschil_coordblack(nu, nieuw);
                }
            pawn test(color::W, cord(0, 0));
            if (test.is_mog_bew(verschil))
            {
                spelbord.play(nu, nieuw);
                ++teller_kleur;
            }
            else {
                std::cout << "geen mogelijke beweging!\n";
            }

        }



        spelbord.printbord();
        return 0;
    }

