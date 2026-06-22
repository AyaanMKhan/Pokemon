#include "pokemon.h"
#include <cstddef>
#include <iostream>

// g++ -std=c++17 main.cpp pokemon.cpp pokedex.cpp -o main

int main() {
    Player player;
    player.generateTeam();

    for(size_t i = 0; i < player.team.size(); i++){
        std::cout << player.team[i].name << "\n";
    }

    return 0;
}