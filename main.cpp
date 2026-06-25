#include "battle.h"
#include "pokemon.h"
#include <iostream>

int countAlive(const Player& player) {
    int alive = 0;
    for (const Pokemon& pokemon : player.team) {
        if (pokemon.isAlive && pokemon.stats.hp > 0) {
            alive++;
        }
    }
    return alive;
}

int main() {
    Player player1;
    player1.generateTeam();

    Player player2;
    player2.generateTeam();

    int activeIndex1 = 0;
    int activeIndex2 = 0;

    std::cout << "Player 1 team:" << std::endl;
    for (const Pokemon& pokemon : player1.team) {
        std::cout << pokemon.name << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Player 2 team:" << std::endl;
    for (const Pokemon& pokemon : player2.team) {
        std::cout << pokemon.name << std::endl;
    }

    std::cout << std::endl;

    while (countAlive(player1) > 0 && countAlive(player2) > 0) {
        const Pokemon& activePokemon1 = player1.team[activeIndex1];
        const Pokemon& activePokemon2 = player2.team[activeIndex2];

        std::cout << "Active Pokemon for Player 1: " << activePokemon1.name << std::endl;
        std::cout << "Health: " << activePokemon1.stats.hp << std::endl;
        std::cout << std::endl;
        std::cout << "Active Pokemon for Player 2: " << activePokemon2.name << std::endl;
        std::cout << "Health: " << activePokemon2.stats.hp << std::endl;
        std::cout << std::endl;

        executeTurn(player1, player2, activeIndex1, activeIndex2);

        if (!player1.team[activeIndex1].isAlive || player1.team[activeIndex1].stats.hp <= 0) {
            if (countAlive(player1) == 0) {
                break;
            }
            std::cout << "Player 1 must switch Pokemon!" << std::endl;
            int switchInput = 0;
            std::cout << "Choose a replacement:" << std::endl;
            for (int i = 0; i < static_cast<int>(player1.team.size()); i++) {
                if (player1.team[i].isAlive && player1.team[i].stats.hp > 0) {
                    std::cout << i + 1 << ": " << player1.team[i].name << std::endl;
                }
            }
            std::cin >> switchInput;
            activeIndex1 = switchPokemon(player1, activeIndex1, switchInput - 1);
            std::cout << player1.team[activeIndex1].name << " was sent out!" << std::endl;
            applyEntryHazards(player1, player1.team[activeIndex1]);
        }

        if (!player2.team[activeIndex2].isAlive || player2.team[activeIndex2].stats.hp <= 0) {
            if (countAlive(player2) == 0) {
                break;
            }
            std::cout << "Player 2 must switch Pokemon!" << std::endl;
            int switchInput = 0;
            std::cout << "Choose a replacement:" << std::endl;
            for (int i = 0; i < static_cast<int>(player2.team.size()); i++) {
                if (player2.team[i].isAlive && player2.team[i].stats.hp > 0) {
                    std::cout << i + 1 << ": " << player2.team[i].name << std::endl;
                }
            }
            std::cin >> switchInput;
            activeIndex2 = switchPokemon(player2, activeIndex2, switchInput - 1);
            std::cout << player2.team[activeIndex2].name << " was sent out!" << std::endl;
            applyEntryHazards(player2, player2.team[activeIndex2]);
        }
    }

    if (countAlive(player1) == 0) {
        std::cout << "Player 2 wins!" << std::endl;
    } else {
        std::cout << "Player 1 wins!" << std::endl;
    }

    return 0;
}
