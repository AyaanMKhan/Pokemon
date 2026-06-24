#include "pokemon.h"
#include <cstddef>
#include <iostream>
#include "typechart.h"
#include "battle.h"

// g++ -std=c++17 main.cpp pokemon.cpp pokedex.cpp -o main








int main() {
    Player player;
    player.generateTeam();   

    int currentPokemonIndex = 0;
    
    Pokemon activePokemon1 = player.team[currentPokemonIndex];
    

    for(int i = 0; i < player.team.size(); i++){
        std::cout << player.team[i].name << std::endl;
    }

    int input = 0;

    while(input != 3){
        std::cout << "Active Pokemon is: " << activePokemon1.name << std::endl;
        std::cout << "Health: " << activePokemon1.stats.hp << std::endl;

        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Switch Pokemon" << std::endl;

        std::cin >> input;
        

        if(input == 2){
            int switchIndex{};
            std::cout << "Which pokemon would you like to switch to?" << std::endl;
            for(int i = 0; i < player.team.size(); i++){
                if(i != currentPokemonIndex){
                    std::cout << i+1 << ": " << player.team[i].name << std::endl;
                }
                
            }

            std::cin >> switchIndex;

            currentPokemonIndex = switchPokemon(player, currentPokemonIndex, switchIndex-1);
            activePokemon1 = player.team[currentPokemonIndex];

            std::cout << activePokemon1.name << " has come out to battle!" << std::endl;
            
        } else if(input == 3){
            break;
        } else {
            continue;
        }
    }
    

    
    return 0;
}