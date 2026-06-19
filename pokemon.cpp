#include "pokemon.h"

PokemonMoves::PokemonMoves(
    std::string name,
    PokemonType type,
    PokemonMoveCategory category,
    double movePower,
    double moveAccuracy,
    int movePp,
    int movePriority
)
    : moveName(name),
      moveType(type),
      moveCategory(category),
      power(movePower),
      accuracy(moveAccuracy),
      pp(movePp),
      priority(movePriority)
{
}

PokemonStats::PokemonStats(int hp, int atk, int def, int spa, int spd, int spe)
    : HP(hp), Atk(atk), Def(def), SpA(spa), SpD(spd), Spe(spe)
{
}

Pokemon::Pokemon(
    int pokemonNum,
    std::string pokemonName,
    std::array<PokemonType, 2> pokemonType,
    std::array<PokemonMoves, 4> pokemonMoves,
    PokemonStats pokemonStats
)
    : pokedexNum(pokemonNum),
      name(pokemonName),
      type(pokemonType),
      moves(pokemonMoves),
      stats(pokemonStats)
{
}

Player::Player(std::vector<Pokemon> team)
    : pokemonTeam(team)
{
}