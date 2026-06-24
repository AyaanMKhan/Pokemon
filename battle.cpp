#include <iostream>
#include <vector>
#include "pokemon.h"
#include "typechart.h"
#include <cstdlib>
#include <ctime>

const std::vector<std::vector<double>> matrix = getTypeChart();

double attack(Pokemon activePokemon1, Pokemon activePokemon2){
    if(activePokemon1.stats.hp <= 0){
        std::cout << "Your pokemon has fainted! " << std::endl;
        return 0;
    }
    int input = 0;
    
    std::cout << "Choose an attack!: " << std::endl;
    for(int i = 0; i < activePokemon1.moves.size(); i++){
        std::cout << i+1 << ": " << activePokemon1.moves[i].name << std::endl;
    }

    std::cin >> input;
    PokemonMove attackMove = activePokemon1.moves[input-1];

    
    if(input > 4 || input <= 0){
        std::cout << "Please select valid attack: " << std::endl;
    }  else {
        std::cout << "User selected: " << attackMove.name << std::endl;
    }
    int moveType = static_cast<int>(attackMove.category);
    int accuracy = attackMove.accuracy;
    int level = 50; // All pokemon are level 50;
    srand(time(0));

    int roll = rand() % 100 + 1;        // Random number from 1 to 100

    if(roll > accuracy){
        std::cout << attackMove.name << " missed!" << std::endl;
        return 0;
    } else {
        if(moveType == 0){
            double power = attackMove.power;
            double attack = activePokemon1.stats.attack;
            double defense = activePokemon2.stats.defense;
            double damage = ((2 * level / 50) * power * attack / defense / 50 * 2);

            // Random damage roll: 85% to 100%
            int roll = rand() % 16 + 85;
            double randomMultiplier = roll / 100.0;
            
            int type = static_cast<int>(attackMove.type);
            int pokemonType1 = static_cast<int>(activePokemon2.types[0]);
            int pokemonType2 = static_cast<int>(activePokemon2.types[1]);

            double val1 = matrix[type][pokemonType1];
            double val2 = matrix[type][pokemonType2];
            double multi = val1 * val2;

            if(multi >= 2.0){
                std::cout << "Super Effective !" << std::endl;
            } else if(multi >= 1.0) {
                std::cout << "Effective !" << std::endl;
            } else if(multi >= 0.25){
                std::cout << "Not very effective"  << std::endl;
            } else if(multi == 0){
                std::cout << "Not affected by attack" << std::endl;
            }

            return damage*multi*randomMultiplier;
        } else if(moveType == 1){
            double power = activePokemon1.moves[input-1].power;
            double SPEattack = activePokemon1.stats.specialAttack;
            double SPEdefense = activePokemon2.stats.specialDefense;
            double damage = ((2 * level / 50) * power * SPEattack / SPEdefense / 50 * 2);
            int roll = rand() % 16 + 85;
            double randomMultiplier = roll / 100.0;

            int type = static_cast<int>(attackMove.type);
            int pokemonType1 = static_cast<int>(activePokemon2.types[0]);
            int pokemonType2 = static_cast<int>(activePokemon2.types[1]);

            double val1 = matrix[type][pokemonType1];
            double val2 = matrix[type][pokemonType2];
            double multi = val1 * val2;
            

            if(multi >= 2.0){
                std::cout << "Super Effective !" << std::endl;
            } else if(multi >= 1.0) {
                std::cout << "Effective !" << std::endl;
            } else if(multi >= 0.25){
                std::cout << "Not very effective" << std::endl;
            } else if(multi == 0){
                std::cout << "Not affected by attack" << std::endl;
            }
            return damage*multi*randomMultiplier;
        } else {
            std::cout << "Status" << std::endl;
            return 0;
        }

    }

}


int switchPokemon(Player player, int activeIndex, int switchIndex){

    if(activeIndex == switchIndex){
        std::cout << "This pokemon is already battling!";
        return activeIndex;
    }

    if(player.team[switchIndex].isAlive){
        

        return switchIndex;
    } else {
        std::cout << "This pokemon has fainted!";
        return activeIndex;
    }
    
}