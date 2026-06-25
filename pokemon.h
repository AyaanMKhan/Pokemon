#pragma once

#include <string>
#include <array>
#include <vector>

enum class PokemonMoveCategory {
    Physical,
    Special,
    Status,
};

enum class StatusCondition {
    None,
    Burn,
    Paralysis,
    Poison,
    BadlyPoisoned,
};



enum class PokemonType {
    Normal,
    Fighting,
    Flying,
    Poison,
    Ground,
    Rock,
    Bug,
    Ghost,
    Steel,
    Fire,
    Water,
    Grass,
    Electric,
    Psychic,
    Ice,
    Dragon,
    Dark,
    Fairy,
    None,
    Count
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
        bool isAlive = true;
        int pokedexNumber;
        std::string name;
        std::array<PokemonType, 2> types;
        std::array<PokemonMove, 4> moves;
        PokemonStats stats;
        int maxHp = 0;
        StatusCondition status = StatusCondition::None;
        int toxicCounter = 0;
        int attackStage = 0;
        int specialAttackStage = 0;
        int speedStage = 0;

    Pokemon();
    Pokemon(int pokedexNumber, std::string name, std::array<PokemonType, 2> types, std::array<PokemonMove, 4> moves, PokemonStats stats);
};


class Player {
    public:
        std::array<Pokemon, 6> team;
        bool stealthRock = false;

    Player();
    void generateTeam();
};


std::string pokemonTypeToString(PokemonType type);
std::string statusConditionToString(StatusCondition status);