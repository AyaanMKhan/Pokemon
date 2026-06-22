#include "pokemon.h"
#include "pokedex.h"
#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
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