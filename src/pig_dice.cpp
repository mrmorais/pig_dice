#include <iostream>  // std::cout, std::cin, std::endl
#include <string>    // std::string

#include "../include/dice.h"

/// String representation for the dice's faces.
const std::string dice_faces[] = { "\u2680", "\u2681", "\u2682", "\u2683", "\u2684", "\u2685" };

int main( void )
{
	int roud_a = 0, roud_b = 0, total_a = 0, total_b = 0, valor = 0;

	std::cout << "Jogador 1 \n";
	bool hold = false;

	enum player {PLAYER_A, PLAYER_B};

	enum player atual = PLAYER_A;

	while (total_a < 100 or total_b < 100) { 
		int *roud, *total;
		if (atual == PLAYER_A) {
			std::cout << ">> JOGADOR A \n";
			roud = &roud_a;
			total = &total_a;
		} else {
			std::cout << ">> JOGADOR B \n";
			roud = &roud_b;
			total = &total_b;
		}
		*roud = 0;

		do {
			hold = false;
			valor = roll();
			std::cout << dice_faces[valor] << "\n";
			if (valor > 0) {
				std::cout << "Valor do round: "<< *roud + valor + 1 << "\n";
				std::cout << "Sair? (1|0)\n";
				std::cin >> hold;
				*roud += valor + 1;
			}
		} while(valor > 0 && !hold);

		if (valor != 0) {
			*total += *roud;
		}

		std::cout << ">> TOTAL ACUMULADO: " << *total << "\n";

		if (atual == PLAYER_A) {
			atual = PLAYER_B;
		} else {
			atual = PLAYER_A;
		}
	}
    // Roll the dice 10 times.
    //for ( auto times(0u) ; times < 10 ; ++times )
    //    std::cout << ">>> Roll: " << dice_faces[ roll() ] << std::endl;
	

    return EXIT_SUCCESS;
}
