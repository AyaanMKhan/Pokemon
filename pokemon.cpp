#include "pokemon.h"
#include "pokedex.h"
#include <algorithm>
#include <array>
#include <cstddef>
#include <numeric>
#include <random>
#include <vector>

Pokemon::Pokemon() = default;

Pokemon::Pokemon(
    
    int pokedexNumber,
    std::string name,
    std::array<PokemonType, 2> types,
    std::array<PokemonMove, 4> moves,
    PokemonStats stats)
{
    this->pokedexNumber = pokedexNumber;
    this->name = name;
    this->types = types;
    this->moves = moves;
    this->stats = stats;
    this->maxHp = stats.hp;
}


Player::Player() = default;

void Player::generateTeam() {
    PokeDex pokedex;
    pokedex.addPokemon();

    if (pokedex.dex.size() < team.size()) {
        return;
    }

    std::random_device rd;
    std::mt19937 rng(rd());

    std::vector<size_t> indices(pokedex.dex.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), rng);

    for (size_t i = 0; i < team.size(); i++) {
        team[i] = pokedex.dex[indices[i]];
    }

    
}

std::string pokemonTypeToString(PokemonType type)
{
    switch (type) {
        case PokemonType::Normal: return "Normal";
        case PokemonType::Fighting: return "Fighting";
        case PokemonType::Flying: return "Flying";
        case PokemonType::Poison: return "Poison";
        case PokemonType::Ground: return "Ground";
        case PokemonType::Rock: return "Rock";
        case PokemonType::Bug: return "Bug";
        case PokemonType::Ghost: return "Ghost";
        case PokemonType::Steel: return "Steel";
        case PokemonType::Fire: return "Fire";
        case PokemonType::Water: return "Water";
        case PokemonType::Grass: return "Grass";
        case PokemonType::Electric: return "Electric";
        case PokemonType::Psychic: return "Psychic";
        case PokemonType::Ice: return "Ice";
        case PokemonType::Dragon: return "Dragon";
        case PokemonType::Dark: return "Dark";
        case PokemonType::Fairy: return "Fairy";
        case PokemonType::None: return "None";
        default: return "Unknown";
    }
}

std::string statusConditionToString(StatusCondition status) {
    switch (status) {
        case StatusCondition::Burn: return "burned";
        case StatusCondition::Paralysis: return "paralyzed";
        case StatusCondition::Poison: return "poisoned";
        case StatusCondition::BadlyPoisoned: return "badly poisoned";
        default: return "";
    }
}