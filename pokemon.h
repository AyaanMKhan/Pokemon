#pragma once

#include <array>
#include <string>

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
	std::string moveName{};
	PokemonType moveType{PokemonType::Normal};
	PokemonMoveCategory moveCategory{PokemonMoveCategory::Status};
	double power{0.0};
	double accuracy{1.0};
	int pp{0};

	PokemonMoves() = default;
	PokemonMoves(std::string name, PokemonType type, PokemonMoveCategory category, double movePower, double moveAccuracy, int movePp);
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
	PokemonStats(int hp, int atk, int def, int spa, int spd, int spe);
};

class Pokemon {
public:
	int pokedexNum{0};
	std::string name{};
	std::array<PokemonType, 2> type{};
	std::array<PokemonMoves, 4> moves{};
	PokemonStats stats{};

	Pokemon() = default;
	Pokemon(int pokemonNum, std::string pokemonName, std::array<PokemonType, 2> pokemonType, std::array<PokemonMoves, 4> pokemonMoves, PokemonStats pokemonStats);
};

class Player {
public:
	std::array<Pokemon, 6> pokemonTeam{};
};

std::array<Pokemon, 6> generateTeam(const Player& player);