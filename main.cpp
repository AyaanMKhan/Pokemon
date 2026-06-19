#include "pokemon.h"

#include <iostream>

int main()
{
    Player player(generateTeam());

    std::cout << "Generated Pokemon Team:\n";
    std::cout << "=======================\n";

    for (const Pokemon& pokemon : player.pokemonTeam) {
        std::cout << pokemon.name << '\n';
    }

    return 0;
}