#include <iostream>
#include <vector>
#include "pokemon.h"
#include "typechart.h"

const std::vector<std::vector<double>> matrix = getTypeChart();

void attack(Pokemon activePokemon, std::array<PokemonType, 2> enemyPokemonType){

    

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