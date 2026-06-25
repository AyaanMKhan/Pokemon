#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "battle.h"
#include "typechart.h"

const std::vector<std::vector<double>> matrix = getTypeChart();

static bool hasType(const Pokemon& pokemon, PokemonType type) {
    return pokemon.types[0] == type || pokemon.types[1] == type;
}

static void checkFaint(Pokemon& pokemon) {
    if (pokemon.stats.hp <= 0) {
        pokemon.stats.hp = 0;
        if (pokemon.isAlive) {
            pokemon.isAlive = false;
            std::cout << pokemon.name << " has fainted!" << std::endl;
        }
    }
}

static void consumePp(PokemonMove& move) {
    if (move.pp > 0) {
        move.pp--;
    }
}

static bool rollAccuracy(int accuracy) {
    if (accuracy <= 0) {
        return true;
    }
    return rand() % 100 + 1 <= accuracy;
}

static double getStatStageMultiplier(int stage) {
    stage = std::max(-6, std::min(6, stage));
    if (stage >= 0) {
        return (2.0 + stage) / 2.0;
    }
    return 2.0 / (2.0 - stage);
}

static int getEffectiveSpeed(const Pokemon& pokemon) {
    double speed = pokemon.stats.speed * getStatStageMultiplier(pokemon.speedStage);
    if (pokemon.status == StatusCondition::Paralysis) {
        speed /= 2.0;
    }
    return static_cast<int>(speed);
}

static int getEffectiveAttack(const Pokemon& pokemon) {
    double attack = pokemon.stats.attack * getStatStageMultiplier(pokemon.attackStage);
    if (pokemon.status == StatusCondition::Burn) {
        attack /= 2.0;
    }
    return static_cast<int>(attack);
}

static int getEffectiveSpecialAttack(const Pokemon& pokemon) {
    return static_cast<int>(pokemon.stats.specialAttack * getStatStageMultiplier(pokemon.specialAttackStage));
}

static bool tryApplyStatus(Pokemon& target, StatusCondition newStatus, int toxicCounter = 0) {
    if (target.status != StatusCondition::None) {
        std::cout << "But it failed!" << std::endl;
        return false;
    }

    target.status = newStatus;
    target.toxicCounter = toxicCounter;
    std::cout << target.name << " was " << statusConditionToString(newStatus) << "!" << std::endl;
    return true;
}

static double getRockEffectiveness(const Pokemon& pokemon) {
    int rockType = static_cast<int>(PokemonType::Rock);
    double val1 = matrix[rockType][static_cast<int>(pokemon.types[0])];
    double val2 = matrix[rockType][static_cast<int>(pokemon.types[1])];
    return val1 * val2;
}

void applyEntryHazards(Player& player, Pokemon& pokemon) {
    if (!player.stealthRock || pokemon.stats.hp <= 0) {
        return;
    }

    double effectiveness = getRockEffectiveness(pokemon);
    if (effectiveness == 0) {
        std::cout << pokemon.name << " is unaffected by Stealth Rock!" << std::endl;
        return;
    }

    int damage = static_cast<int>(pokemon.maxHp * effectiveness / 8.0);
    if (damage < 1) {
        damage = 1;
    }

    pokemon.stats.hp -= damage;
    std::cout << "Pointed stones dug into " << pokemon.name << "!" << std::endl;
    checkFaint(pokemon);
}

static void applyStatusMove(
    Pokemon& attacker,
    Pokemon& defender,
    const PokemonMove& move,
    Player& attackerPlayer,
    Player& defenderPlayer) {
    if (!rollAccuracy(move.accuracy)) {
        std::cout << move.name << " missed!" << std::endl;
        return;
    }

    if (move.name == "Thunder Wave") {
        if (hasType(defender, PokemonType::Ground) || hasType(defender, PokemonType::Electric)) {
            std::cout << "It doesn't affect " << defender.name << "..." << std::endl;
            return;
        }
        tryApplyStatus(defender, StatusCondition::Paralysis);
        return;
    }

    if (move.name == "Will-O-Wisp") {
        if (hasType(defender, PokemonType::Fire)) {
            std::cout << "It doesn't affect " << defender.name << "..." << std::endl;
            return;
        }
        tryApplyStatus(defender, StatusCondition::Burn);
        return;
    }

    if (move.name == "Toxic") {
        if (hasType(defender, PokemonType::Poison) || hasType(defender, PokemonType::Steel)) {
            std::cout << "It doesn't affect " << defender.name << "..." << std::endl;
            return;
        }
        tryApplyStatus(defender, StatusCondition::BadlyPoisoned, 1);
        return;
    }

    if (move.name == "Stealth Rock") {
        if (defenderPlayer.stealthRock) {
            std::cout << "But it failed!" << std::endl;
            return;
        }
        defenderPlayer.stealthRock = true;
        std::cout << "Pointed stones float around the opposing team!" << std::endl;
        return;
    }

    if (move.name == "Defog") {
        attackerPlayer.stealthRock = false;
        defenderPlayer.stealthRock = false;
        std::cout << "The fog lifted!" << std::endl;
        return;
    }

    if (move.name == "Moonlight") {
        int healAmount = attacker.maxHp / 2;
        int oldHp = attacker.stats.hp;
        attacker.stats.hp = std::min(attacker.maxHp, attacker.stats.hp + healAmount);
        std::cout << attacker.name << " restored HP! (" << oldHp << " -> " << attacker.stats.hp << ")" << std::endl;
        return;
    }

    if (move.name == "Agility") {
        if (attacker.speedStage >= 6) {
            std::cout << attacker.name << "'s Speed won't go any higher!" << std::endl;
            return;
        }
        attacker.speedStage = std::min(6, attacker.speedStage + 2);
        std::cout << attacker.name << "'s Speed sharply rose!" << std::endl;
        return;
    }

    if (move.name == "Nasty Plot") {
        if (attacker.specialAttackStage >= 6) {
            std::cout << attacker.name << "'s Sp. Atk won't go any higher!" << std::endl;
            return;
        }
        attacker.specialAttackStage = std::min(6, attacker.specialAttackStage + 2);
        std::cout << attacker.name << "'s Sp. Atk sharply rose!" << std::endl;
        return;
    }

    std::cout << "But nothing happened!" << std::endl;
}

static void applyEndOfTurnStatus(Pokemon& pokemon) {
    if (pokemon.stats.hp <= 0) {
        return;
    }

    int damage = 0;
    if (pokemon.status == StatusCondition::Burn || pokemon.status == StatusCondition::Poison) {
        damage = std::max(1, pokemon.maxHp / 16);
    } else if (pokemon.status == StatusCondition::BadlyPoisoned) {
        if (pokemon.toxicCounter < 1) {
            pokemon.toxicCounter = 1;
        }
        damage = std::max(1, pokemon.maxHp * pokemon.toxicCounter / 16);
        pokemon.toxicCounter++;
    }

    if (damage <= 0) {
        return;
    }

    pokemon.stats.hp -= damage;
    std::cout << pokemon.name << " is hurt by its " << statusConditionToString(pokemon.status) << "! (-" << damage << " HP)" << std::endl;
    checkFaint(pokemon);
}

static bool isFullyParalyzed(const Pokemon& pokemon) {
    if (pokemon.status != StatusCondition::Paralysis) {
        return false;
    }
    if (rand() % 100 < 25) {
        std::cout << pokemon.name << " is paralyzed! It can't move!" << std::endl;
        return true;
    }
    return false;
}

double calculateAttackDamage(const Pokemon& activePokemon1, const Pokemon& activePokemon2, int moveIndex) {
    if (activePokemon1.stats.hp <= 0) {
        std::cout << "Your pokemon has fainted!" << std::endl;
        return 0;
    }

    if (moveIndex < 0 || moveIndex >= static_cast<int>(activePokemon1.moves.size())) {
        std::cout << "Invalid move selected." << std::endl;
        return 0;
    }

    const PokemonMove& attackMove = activePokemon1.moves[moveIndex];

    if (attackMove.category == PokemonMoveCategory::Status) {
        return 0;
    }

    if (!rollAccuracy(attackMove.accuracy)) {
        std::cout << attackMove.name << " missed!" << std::endl;
        return 0;
    }

    int level = 50;
    double power = attackMove.power;

    if (attackMove.category == PokemonMoveCategory::Physical) {
        double attack = getEffectiveAttack(activePokemon1);
        double defense = activePokemon2.stats.defense;
        double damage = ((2 * level / 50) * power * attack / defense / 50 * 2);

        int damageRoll = rand() % 16 + 85;
        double randomMultiplier = damageRoll / 100.0;

        int type = static_cast<int>(attackMove.type);
        int pokemonType1 = static_cast<int>(activePokemon2.types[0]);
        int pokemonType2 = static_cast<int>(activePokemon2.types[1]);

        double val1 = matrix[type][pokemonType1];
        double val2 = matrix[type][pokemonType2];
        double multi = val1 * val2;

        if (multi >= 2.0) {
            std::cout << "Super Effective !" << std::endl;
        } else if (multi >= 1.0) {
            std::cout << "Effective !" << std::endl;
        } else if (multi >= 0.25) {
            std::cout << "Not very effective" << std::endl;
        } else if (multi == 0) {
            std::cout << "Not affected by attack" << std::endl;
        }

        return damage * multi * randomMultiplier;
    }

    double specialAttack = getEffectiveSpecialAttack(activePokemon1);
    double specialDefense = activePokemon2.stats.specialDefense;
    double damage = ((2 * level / 50) * power * specialAttack / specialDefense / 50 * 2);
    int damageRoll = rand() % 16 + 85;
    double randomMultiplier = damageRoll / 100.0;

    int type = static_cast<int>(attackMove.type);
    int pokemonType1 = static_cast<int>(activePokemon2.types[0]);
    int pokemonType2 = static_cast<int>(activePokemon2.types[1]);

    double val1 = matrix[type][pokemonType1];
    double val2 = matrix[type][pokemonType2];
    double multi = val1 * val2;

    if (multi >= 2.0) {
        std::cout << "Super Effective !" << std::endl;
    } else if (multi >= 1.0) {
        std::cout << "Effective !" << std::endl;
    } else if (multi >= 0.25) {
        std::cout << "Not very effective" << std::endl;
    } else if (multi == 0) {
        std::cout << "Not affected by attack" << std::endl;
    }
    return damage * multi * randomMultiplier;
}

BattleAction getPlayerAction(const Player& player, int activeIndex, int playerNum) {
    BattleAction action{};
    action.playerNum = playerNum;

    const Pokemon& activePokemon = player.team[activeIndex];

    std::cout << "Player " << playerNum << " - choose an action:" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Switch Pokemon" << std::endl;

    int input = 0;
    std::cin >> input;

    if (input == 2) {
        int switchInput = 0;
        std::cout << "Which pokemon would you like to switch to?" << std::endl;
        for (int i = 0; i < static_cast<int>(player.team.size()); i++) {
            if (i != activeIndex) {
                std::cout << i + 1 << ": " << player.team[i].name << std::endl;
            }
        }
        std::cin >> switchInput;
        action.type = BattleActionType::Switch;
        action.index = switchInput - 1;
        return action;
    }

    int moveInput = 0;
    std::cout << "Choose an attack:" << std::endl;
    for (int i = 0; i < static_cast<int>(activePokemon.moves.size()); i++) {
        std::cout << i + 1 << ": " << activePokemon.moves[i].name << std::endl;
    }
    std::cin >> moveInput;

    if (moveInput <= 0 || moveInput > static_cast<int>(activePokemon.moves.size())) {
        std::cout << "Invalid attack, defaulting to first move." << std::endl;
        moveInput = 1;
    }

    action.type = BattleActionType::Attack;
    action.index = moveInput - 1;
    return action;
}

int switchPokemon(Player& player, int activeIndex, int switchIndex) {
    if (activeIndex == switchIndex) {
        std::cout << "This pokemon is already battling!" << std::endl;
        return activeIndex;
    }

    if (player.team[switchIndex].isAlive && player.team[switchIndex].stats.hp > 0) {
        return switchIndex;
    }

    std::cout << "This pokemon has fainted!" << std::endl;
    return activeIndex;
}

static int getActionPriority(const BattleAction& action, const Pokemon& activePokemon) {
    if (action.type == BattleActionType::Switch) {
        return SWITCH_PRIORITY;
    }
    return activePokemon.moves[action.index].priority;
}

static void performSwitch(Player& player, int& activeIndex, int playerNum, int switchIndex) {
    int newIndex = switchPokemon(player, activeIndex, switchIndex);
    if (newIndex != activeIndex) {
        activeIndex = newIndex;
        std::cout << "Player " << playerNum << " sent out " << player.team[activeIndex].name << "!" << std::endl;
        applyEntryHazards(player, player.team[activeIndex]);
    }
}

static void performAttack(
    Player& attackerPlayer,
    Player& defenderPlayer,
    int attackerIndex,
    int defenderIndex,
    int moveIndex) {
    Pokemon& attacker = attackerPlayer.team[attackerIndex];
    Pokemon& defender = defenderPlayer.team[defenderIndex];

    if (attacker.stats.hp <= 0 || defender.stats.hp <= 0) {
        return;
    }

    PokemonMove& move = attacker.moves[moveIndex];

    if (move.pp <= 0) {
        std::cout << move.name << " has no PP left!" << std::endl;
        return;
    }

    std::cout << attacker.name << " used " << move.name << "!" << std::endl;
    consumePp(move);

    if (move.category == PokemonMoveCategory::Status) {
        applyStatusMove(attacker, defender, move, attackerPlayer, defenderPlayer);
        return;
    }

    double damage = calculateAttackDamage(attacker, defender, moveIndex);
    defender.stats.hp -= static_cast<int>(damage);
    checkFaint(defender);
}

void executeTurn(Player& player1, Player& player2, int& activeIndex1, int& activeIndex2) {
    srand(static_cast<unsigned>(time(nullptr)));

    BattleAction action1 = getPlayerAction(player1, activeIndex1, 1);
    BattleAction action2 = getPlayerAction(player2, activeIndex2, 2);

    std::vector<BattleAction> actions = {action1, action2};

    std::sort(actions.begin(), actions.end(), [&](const BattleAction& a, const BattleAction& b) {
        const Pokemon& activeA = (a.playerNum == 1) ? player1.team[activeIndex1] : player2.team[activeIndex2];
        const Pokemon& activeB = (b.playerNum == 1) ? player1.team[activeIndex1] : player2.team[activeIndex2];

        int priorityA = getActionPriority(a, activeA);
        int priorityB = getActionPriority(b, activeB);
        if (priorityA != priorityB) {
            return priorityA > priorityB;
        }

        int speedA = getEffectiveSpeed(activeA);
        int speedB = getEffectiveSpeed(activeB);
        if (speedA != speedB) {
            return speedA > speedB;
        }

        return a.playerNum < b.playerNum;
    });

    std::cout << std::endl << "--- Turn resolution ---" << std::endl << std::endl;

    for (const BattleAction& action : actions) {
        if (action.playerNum == 1) {
            if (action.type == BattleActionType::Switch) {
                performSwitch(player1, activeIndex1, 1, action.index);
            } else if (!isFullyParalyzed(player1.team[activeIndex1])) {
                performAttack(player1, player2, activeIndex1, activeIndex2, action.index);
            }
        } else {
            if (action.type == BattleActionType::Switch) {
                performSwitch(player2, activeIndex2, 2, action.index);
            } else if (!isFullyParalyzed(player2.team[activeIndex2])) {
                performAttack(player2, player1, activeIndex2, activeIndex1, action.index);
            }
        }
        std::cout << std::endl;
    }

    applyEndOfTurnStatus(player1.team[activeIndex1]);
    applyEndOfTurnStatus(player2.team[activeIndex2]);

    std::cout << std::endl << "--- End of turn ---" << std::endl << std::endl;
}
