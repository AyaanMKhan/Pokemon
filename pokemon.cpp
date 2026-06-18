#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include "pokedex.h"
#include <random>

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
        int priority;

        PokemonMoves() = default;

        PokemonMoves(std::string name, PokemonType type, PokemonMoveCategory category, double movePower, double moveAccuracy, int movePp, int movePriority){
            moveName = name;
            moveType = type;
            moveCategory = category;
            power = movePower;
            accuracy = moveAccuracy;
            pp = movePp;
            priority = movePriority;
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

        Pokemon() = default;

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
        std::vector<Pokemon> pokemonTeam;

        
        Player(std::vector<Pokemon> team){
            pokemonTeam = team;
        }
};

std::vector<Pokemon> generateTeam(Player player){
    
    PokeDex pokeDex;
    pokeDex.addPokemon();
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<std::size_t> distr(0, pokeDex.dex.size()-1);

    while(player.pokemonTeam.size() < 6){
        std::size_t random_index = distr(gen);
        Pokemon randomPokemon = pokeDex.dex[random_index];

        player.pokemonTeam.push_back(randomPokemon);
    }
    
    
    return player.pokemonTeam;
} 

int main(){

    Player player(generateTeam(player));

    for(int i = 0; i < player.pokemonTeam.size(); i++){
        std::cout << player.pokemonTeam[i].name;
    }

    return 0;
}