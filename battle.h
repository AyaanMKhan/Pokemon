#include <iostream>
#include <vector>
#include "pokemon.h"
#include "typechart.h"

void attack(std::array<PokemonType, 2> type1, std::array<PokemonType, 2> type2);

int switchPokemon(Player player, int activeIndex, int switchIndex);