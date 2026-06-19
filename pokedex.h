#pragma once

#include "pokemon.h"

#include <vector>

class PokeDex {
public:
    std::vector<Pokemon> dex{};

    void addPokemon();
};