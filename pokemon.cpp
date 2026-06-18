#include <iostream>
#include <array>
#include <string>
#include <string_view>

enum class PokemonType {
    Normal,
    Fire, 
    Water,
    Grass,
    Dark,
    Ghost,
    Poison,
    Bug,
    Electric,
    Ground,
    Rock,
    Flying,
    Ice,
    Dragon,
    Fairy,
    Psychic,
    Steel,
    Fighting,
};

enum class PokemonMoveCategory {
    SpecialAttack,
    Attack,
    Status
};

class PokemonMoves {
    public:
        std::string moveName;
        PokemonType moveType;
        PokemonMoveCategory moveCategory;
        double power;
        double accuracy;
        int pp;

        PokemonMoves() = default;

        PokemonMoves(std::string name, PokemonType type, PokemonMoveCategory category, double movePower, double moveAccuracy, int movePp){
            moveName = name;
            moveType = type;
            moveCategory = category;
            power = movePower;
            accuracy = moveAccuracy;
            pp = movePp;
        }
};

class PokemonStats {
    public:
        int HP{0};
        int Atk{0};
        int Def{0};
        int SpA{0};
        int SpD{0};
        int Spe{0};

        PokemonStats() = default;

        PokemonStats(int hp, int atk, int def, int spa, int spd, int spe){
            HP = hp;
            Atk = atk;
            Def = def;
            SpA = spa;
            SpD = spd;
            Spe = spe;
        }
};



class Pokemon{
    public:
        int pokedexNum;
        std::string name;
        std::array<PokemonType, 2> type{};
        std::array<PokemonMoves, 4> moves{};
        PokemonStats stats;

        Pokemon(int pokemonNum, std::string pokemonName, std::array<PokemonType, 2> pokemonType, std::array<PokemonMoves, 4> pokemonMoves, PokemonStats pokemonStats){
            pokedexNum = pokemonNum;
            name = pokemonName;
            type = pokemonType;
            moves = pokemonMoves;
            stats = pokemonStats;
        }
};


class Player{
    public:
        std::array<Pokemon, 6> pokemonTeam;
};

std::array<Pokemon, 6> generateTeam(Player player){

} 

int main(){


    return 0;
}