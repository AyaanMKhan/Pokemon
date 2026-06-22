#include "pokedex.h"
#include "pokemon.h"

void PokeDex::addPokemon()
{
    if (!dex.empty()) {
        return;
    }

    dex.push_back(
        Pokemon(
            36,
            "Clefable",
            std::array<PokemonType, 2>{
                PokemonType::Fairy,
                PokemonType::Normal
            },
            std::array<PokemonMove, 4>{
                PokemonMove{"Moonblast", PokemonType::Fairy, PokemonMoveCategory::Special, 85, 100, 15, 0},
                PokemonMove{"Knock Off", PokemonType::Dark, PokemonMoveCategory::Physical, 65, 100, 20, 0},
                PokemonMove{"Moonlight", PokemonType::Fairy, PokemonMoveCategory::Status, 0, 0, 5, 0},
                PokemonMove{"Stealth Rock", PokemonType::Rock, PokemonMoveCategory::Status, 0, 0, 20, 0}
            },
            PokemonStats{95, 70, 73, 95, 90, 60}
        )
    );

    dex.push_back(
        Pokemon(
            110,
            "Weezing-Galar",
            std::array<PokemonType, 2>{
                PokemonType::Poison,
                PokemonType::Fairy
            },
            std::array<PokemonMove, 4>{
                PokemonMove{"Defog", PokemonType::Flying, PokemonMoveCategory::Status, 0, 0, 15, 0},
                PokemonMove{"Will-O-Wisp", PokemonType::Fire, PokemonMoveCategory::Status, 0, 85, 15, 0},
                PokemonMove{"Sludge Bomb", PokemonType::Poison, PokemonMoveCategory::Special, 90, 100, 10, 0},
                PokemonMove{"Toxic", PokemonType::Poison, PokemonMoveCategory::Status, 0, 90, 10, 0}
            },
            PokemonStats{65, 90, 120, 85, 70, 60}
        )
    );

    dex.push_back(
        Pokemon(
            145,
            "Zapdos",
            std::array<PokemonType, 2>{
                PokemonType::Electric,
                PokemonType::Flying
            },
            std::array<PokemonMove, 4>{
                PokemonMove{"Thunderbolt", PokemonType::Electric, PokemonMoveCategory::Special, 95, 100, 15, 0},
                PokemonMove{"Drill Peck", PokemonType::Flying, PokemonMoveCategory::Physical, 80, 100, 20, 0},
                PokemonMove{"Thunder Wave", PokemonType::Electric, PokemonMoveCategory::Status, 0, 100, 20, 0},
                PokemonMove{"Agility", PokemonType::Psychic, PokemonMoveCategory::Status, 0, 0, 30, 0}
            },
            PokemonStats{90, 90, 85, 125, 125, 100}
        )
    );

    dex.push_back(
        Pokemon(
            146,
            "Moltres",
            std::array<PokemonType, 2>{
                PokemonType::Fire,
                PokemonType::Flying
            },
            std::array<PokemonMove, 4>{
                PokemonMove{"Agility", PokemonType::Psychic, PokemonMoveCategory::Status, 0, 0, 30, 0},
                PokemonMove{"Fire Blast", PokemonType::Fire, PokemonMoveCategory::Special, 120, 85, 5, 0},
                PokemonMove{"Double Edge", PokemonType::Normal, PokemonMoveCategory::Physical, 100, 100, 15, 0},
                PokemonMove{"Hyper Beam", PokemonType::Normal, PokemonMoveCategory::Physical, 150, 90, 5, 0}
            },
            PokemonStats{90, 100, 90, 125, 125, 90}
        )
    );

    dex.push_back(
        Pokemon(
            149,
            "Dragonite",
            std::array<PokemonType, 2>{
                PokemonType::Dragon,
                PokemonType::Flying
            },
            std::array<PokemonMove, 4>{
                PokemonMove{"Thunder Wave", PokemonType::Electric, PokemonMoveCategory::Status, 0, 100, 20, 0},
                PokemonMove{"Blizzard", PokemonType::Ice, PokemonMoveCategory::Special, 120, 90, 5, 0},
                PokemonMove{"Thunderbolt", PokemonType::Electric, PokemonMoveCategory::Special, 95, 100, 15, 0},
                PokemonMove{"Hyper Beam", PokemonType::Normal, PokemonMoveCategory::Physical, 150, 90, 5, 0}
            },
            PokemonStats{91, 134, 95, 100, 100, 80}
        )
    );

    dex.push_back(
        Pokemon(
            199,
            "Slowking-Galar",
            std::array<PokemonType, 2>{
                PokemonType::Poison,
                PokemonType::Psychic
            },
            std::array<PokemonMove, 4>{
                PokemonMove{"Sludge Bomb", PokemonType::Poison, PokemonMoveCategory::Special, 90, 100, 10, 0},
                PokemonMove{"Nasty Plot", PokemonType::Dark, PokemonMoveCategory::Status, 0, 0, 20, 0},
                PokemonMove{"Flamethrower", PokemonType::Fire, PokemonMoveCategory::Special, 90, 100, 15, 0},
                PokemonMove{"Psyshock", PokemonType::Psychic, PokemonMoveCategory::Special, 80, 100, 10, 0}
            },
            PokemonStats{95, 65, 80, 110, 110, 30}
        )
    );
}
