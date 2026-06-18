#include "pokemon.h"

#include <iostream>
#include <array>
#include <string>
#include <vector>



class PokeDex{
    public:
        std::vector<Pokemon> dex;

        std::vector<Pokemon> addPokemon();
};

PokeDex pokedex;


std::vector<Pokemon> addPokemon(){
    
    pokedex.dex.push_back(
        Pokemon(36, "Clefable", {PokemonType::Fairy}, {
            PokemonMoves("Moonblast", PokemonType::Fairy, PokemonMoveCategory::SpecialAttack, 85, 100, 15),
            PokemonMoves("Knock off", PokemonType::Dark, PokemonMoveCategory::Attack, 65, 100, 20),
            PokemonMoves("Moonlight", PokemonType::Fairy, PokemonMoveCategory::Status, 0, 0, 5),
            PokemonMoves("Stealth Rock", PokemonType::Rock, PokemonMoveCategory::Status, 0, 0, 20)
        }, 
        PokemonStats(95, 70, 73, 95, 90, 60))
    );


    return pokedex.dex;
}