#include "pokemon.h"
#include <cstddef>
#include <iostream>
#include "typechart.h"
#include "battle.h"

// g++ -std=c++17 main.cpp pokemon.cpp pokedex.cpp -o main








int main() {
    Player player1;
    player1.generateTeam();   

    Player player2;
    player2.generateTeam();

    int currentPokemonIndex = 0;
    
    Pokemon activePokemon1 = player1.team[currentPokemonIndex];
    Pokemon activePokemon2 = player2.team[currentPokemonIndex];
    
    std::cout << "Player 1: " << std::endl;
    for(int i = 0; i < player1.team.size(); i++){
        std::cout << player1.team[i].name << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Player 2: " << std::endl;
    for(int i = 0; i < player2.team.size(); i++){
        std::cout << player2.team[i].name << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    int input = 0;
    int input2 = 0;
    int TeamCount1 = 6;
    int TeamCount2 = 6;

    while(input != 3){
        std::cout << "Active Pokemon for player1: " << activePokemon1.name << std::endl;
        std::cout << "Health: " << activePokemon1.stats.hp << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Active Pokemon for player2: " << activePokemon2.name << std::endl;
        std::cout << "Health: " << activePokemon2.stats.hp << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Switch Pokemon" << std::endl;

        std::cin >> input;
        if(input == 1){
            std::cout << activePokemon1.name << " will atack " << activePokemon2.name << std::endl;
            double damage = attack(activePokemon1, activePokemon2);
            activePokemon2.stats.hp -= damage;
            if(activePokemon2.stats.hp <= 0){
                activePokemon2.isAlive = 1;
                TeamCount2 -= 1;
                std::cout << activePokemon2.name << " has fainted!" << std::endl;
                continue;
            }
        }

        else if(input == 2){
            int switchIndex{};
            std::cout << "Which pokemon would you like to switch to?" << std::endl;
            for(int i = 0; i < player1.team.size(); i++){
                if(i != currentPokemonIndex){
                    std::cout << i+1 << ": " << player1.team[i].name << std::endl;
                }
                
            }

            std::cin >> switchIndex;

            currentPokemonIndex = switchPokemon(player1, currentPokemonIndex, switchIndex-1);
            activePokemon1 = player1.team[currentPokemonIndex];

            std::cout << activePokemon1.name << " has come out to battle!" << std::endl;
            
        } else {
            continue;
        }
    }
    

    
    return 0;
}