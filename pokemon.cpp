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
};



class Pokemon : public PokemonMoves{
    public:
        std::string name;
        std::array<PokemonType, 2> type{};
        std::array<PokemonMoves, 4> moves{};
};



int main(){

    return 0;
}