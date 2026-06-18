#include "pokedex.h"

PokeDex pokedex;


std::vector<Pokemon> PokeDex::addPokemon(){
    
    dex.push_back(
        Pokemon(36, "Clefable", {PokemonType::Fairy, PokemonType::Normal}, {
            PokemonMoves("Moonblast", PokemonType::Fairy, PokemonMoveCategory::SpecialAttack, 85, 100, 15, 0),
            PokemonMoves("Knock off", PokemonType::Dark, PokemonMoveCategory::Attack, 65, 100, 20, 0),
            PokemonMoves("Moonlight", PokemonType::Fairy, PokemonMoveCategory::Status, 0, 0, 5, 0),
            PokemonMoves("Stealth Rock", PokemonType::Rock, PokemonMoveCategory::Status, 0, 0, 20, 0)
        }, 
        PokemonStats(95, 70, 73, 95, 90, 60))
    );

    dex.push_back(
        Pokemon(110, "Weezing-Galar", {PokemonType::Poison, PokemonType::Fairy}, {
            PokemonMoves("Defog", PokemonType::Flying, PokemonMoveCategory::Status, 0, 0, 15, 0),
            PokemonMoves("Will-o-Wisp", PokemonType::Fire, PokemonMoveCategory::Status, 0, 85, 15, 0),
            PokemonMoves("Sluge Bomb", PokemonType::Poison, PokemonMoveCategory::SpecialAttack, 90, 100, 10, 0),
            PokemonMoves("Toxic", PokemonType::Poison, PokemonMoveCategory::Status, 0, 90, 10, 0)
        },
        PokemonStats(65, 90, 120, 85, 70, 60))
    );

    dex.push_back(
        Pokemon(145, "Zaptos", {PokemonType::Electric, PokemonType::Flying}, {
            PokemonMoves("Thunderbolt", PokemonType::Electric, PokemonMoveCategory::SpecialAttack, 95, 100, 15, 0),
            PokemonMoves("Drill Peck", PokemonType::Flying, PokemonMoveCategory::Attack, 80, 100, 20, 0),
            PokemonMoves("Thunder Wave", PokemonType::Electric, PokemonMoveCategory::Status, 0, 100, 20, 0),
            PokemonMoves("Agility", PokemonType::Psychic, PokemonMoveCategory::Status, 0, 0, 30, 0)
        },
        PokemonStats(90, 90, 85, 125, 125, 100))
    );

    dex.push_back(
        Pokemon(146, "Moltres", {PokemonType::Fire, PokemonType::Flying}, {
            PokemonMoves("Agility", PokemonType::Psychic, PokemonMoveCategory::Status, 0, 0, 30, 0),
            PokemonMoves("Fire Blast", PokemonType::Fire, PokemonMoveCategory::SpecialAttack, 120, 85, 5, 0),
            PokemonMoves("Double Edge", PokemonType::Normal, PokemonMoveCategory::Attack, 100, 100, 15, 0),
            PokemonMoves("Hyper Beam", PokemonType::Normal, PokemonMoveCategory::Attack, 150, 90, 5, 0)
        },
        PokemonStats(90, 100, 90, 125, 125, 90))
    );

    dex.push_back(
        Pokemon(149, "Dragonite", {PokemonType::Dragon, PokemonType::Flying}, {
            PokemonMoves("Thunder Wave", PokemonType::Electric, PokemonMoveCategory::Status, 0, 100, 20, 0),
            PokemonMoves("Blizzard", PokemonType::Ice, PokemonMoveCategory::SpecialAttack, 120, 90, 5, 0),
            PokemonMoves("Thunderbolt", PokemonType::Electric, PokemonMoveCategory::SpecialAttack, 95, 100, 15, 0),
            PokemonMoves("Hyper Beam", PokemonType::Normal, PokemonMoveCategory::Attack, 150, 90, 5, 0)
        },
        PokemonStats(91, 134, 95, 100, 100, 80))
    );


    dex.push_back(
        Pokemon(199, "Slowking-Galar", {PokemonType::Poison, PokemonType::Psychic}, {
            PokemonMoves("Sluge Bomb", PokemonType::Poison, PokemonMoveCategory::SpecialAttack, 90, 100, 10, 0),
            PokemonMoves("Nastly Plot", PokemonType::Dark, PokemonMoveCategory::Status, 0, 0, 20, 0),
            PokemonMoves("Flamethrower", PokemonType::Fire, PokemonMoveCategory::SpecialAttack, 90, 100, 15, 0),
            PokemonMoves("Psyshock", PokemonType::Psychic, PokemonMoveCategory::SpecialAttack, 80, 100, 10, 0)
        },
        PokemonStats(95, 65, 80, 110, 110, 30))
    );

    return dex;
}