#pragma once

#include "pokemon.h"

enum class BattleActionType {
    Attack,
    Switch
};

struct BattleAction {
    int playerNum;
    BattleActionType type;
    int index;
};

constexpr int SWITCH_PRIORITY = 6;

double calculateAttackDamage(const Pokemon& attacker, const Pokemon& defender, int moveIndex);
BattleAction getPlayerAction(const Player& player, int activeIndex, int playerNum);
int switchPokemon(Player& player, int activeIndex, int switchIndex);
void applyEntryHazards(Player& player, Pokemon& pokemon);
void executeTurn(Player& player1, Player& player2, int& activeIndex1, int& activeIndex2);
