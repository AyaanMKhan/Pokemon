#pragma once

#include <string>
#include <array>
#include <vector>

enum class PokemonMoveCategory {
    Physical,
    Special,
    Status,
};

enum class PokemonType {
    Normal,
    Fire,
    Water,
    Grass,
    Electric,
    Ice,
    Fighting,
    Poison,
    Ground,
    Flying,
    Psychic,
    Bug,
    Rock,
    Ghost,
    Dragon,
    Dark,
    Steel,
    Fairy
};

struct PokemonStats {
    int hp;
    int attack;
    int defense;
    int specialAttack;
    int specialDefense;
    int speed;
};

struct PokemonMove {
    std::string name;
    PokemonType type;
    PokemonMoveCategory category;
    int power;
    int accuracy;
    int pp;
    int priority;
};



class Pokemon {
    public:
        int pokedexNumber;
        std::string name;
        std::array<PokemonType, 2> types;
        std::array<PokemonMove, 4> moves;
        PokemonStats stats;
    
    Pokemon();
    Pokemon(int pokedexNumber, std::string name, std::array<PokemonType, 2> types, std::array<PokemonMove, 4> moves, PokemonStats stats);
};


class Player {
    public:
        std::array<Pokemon, 6> team;

    Player();
    void generateTeam();
};