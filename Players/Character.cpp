#include "Character.h"
#include "Player.h"
#include <string>
#include "../Utilities.h"

Character::Character(const std::string &characterType): character(characterType) {
}

std::string Character::getCharacter() {
    return character;
}

Responsible::Responsible(const std::string &characterType) : Character(characterType) {
}

std::string Responsible::potionPurchase(Player &player) {
    int amount = 0;
    while (player.getHealthPoints() < player.getMaxHealthPoints() && player.getCoins() >= 5) {
        player.buySinglePotion();
        amount++;
    }
    return getPotionsPurchaseMessage(player, amount);
}


RiskTaking::RiskTaking(const std::string &characterType) : Character(characterType) {
}

std::string RiskTaking::potionPurchase(Player &player) {
    if (player.getHealthPoints() < 50 && player.getCoins() > 5) {
        player.buySinglePotion();
        return getPotionsPurchaseMessage(player, 1);
    } else {
        return getPotionsPurchaseMessage(player, 0);
    }
}


