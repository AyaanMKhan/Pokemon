#include "pokemon.h"
#include <cstddef>
#include <iostream>
#include "typechart.h"

// g++ -std=c++17 main.cpp pokemon.cpp pokedex.cpp -o main


int main() {
    Player player;
    player.generateTeam();

    for(size_t i = 0; i < player.team.size(); i++){
        std::cout << player.team[i].name << "\n";
    }

    //     std::vector<std::vector<double>> matrix = getTypeChart();
    std::vector<std::vector<double>> matrix = getTypeChart();
    

    int rows = matrix.size();
    
    int cols = matrix[0].size();

    for (int i = 0; i <= rows; i++) {
        PokemonType type = static_cast<PokemonType>(i);

        std::cout << pokemonTypeToString(type) << ": ";

        for (int j = 0; j < cols; j++) {
            PokemonType type2 = static_cast<PokemonType>(j);

            std::cout << pokemonTypeToString(type2) << ": " << matrix[i][j] << " " << std::endl;
        }

        std::cout << std::endl;
    }
    

    return 0;
}