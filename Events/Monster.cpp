# include "Monster.h"
#include "EventFactory.h"
#include <iostream>
#include "../Utilities.h"

Monster::Monster(const string &monsterName) : Event(monsterName) {
}


string Monster::getDescription() const {
    string result = name + " (power " + std::to_string(combatPower) + ", "
                    + "loot " + std::to_string(loot)
                    + ", " + "damage " + std::to_string(damage) + ")";
    return result;
}

string Monster::applyEvent(Player &player) {
    if (combatPower < player.getCombatPower()) {
        player.wonBattle(getLoot());
        return getEncounterWonMessage(player, getLoot());
    } else {
        player.lostBattle(getDamage());
        return getEncounterLostMessage(player, getDamage());
    }
}

int Monster::getDamage() const {
    return damage;
}

int Monster::getLoot() const {
    return loot;
}

int Monster::getCombatPower() const {
    return combatPower;
}

void Monster::postBattle() {
    return;
}

//snail
Snail::Snail(): Monster("Snail") {
    combatPower = 5;
    loot = 2;
    damage = 10;
}


//slime
Slime::Slime(): Monster("Slime") {
    combatPower = 12;
    loot = 5;
    damage = 25;
}


//balrog
Balrog::Balrog(): Monster("Balrog") {
    combatPower = 15;
    loot = 100;
    damage = 9001;
}

string Balrog::applyEvent(Player &player) {
    if (combatPower < player.getCombatPower()) {
        player.wonBattle(getLoot());
        combatPower += 2;
        return getEncounterWonMessage(player, getLoot());
    } else {
        player.lostBattle(getDamage());
        combatPower += 2;
        return getEncounterLostMessage(player, getDamage());
    }
}

void Balrog::postBattle() {
    combatPower += 2;
}


//pack
Pack::Pack(std::istream &eventsStream) : Monster("Pack") {
    eventsStream >> packSize;
    if (packSize < MIN_PACK_SIZE) {
        throw std::runtime_error("Invalid Events File");
    }
    for (int i = 0; i < packSize; i++) {
        pack.push_back(MonsterFactory::createMonster(eventsStream));
    }
    for (std::vector<std::unique_ptr<Monster> >::iterator it = pack.begin(); it != pack.end(); ++it) {
        combatPower += it.operator*()->getCombatPower();
        loot += it.operator*()->getLoot();
        damage += it.operator*()->getDamage();
    }
}

string Pack::getDescription() const {
    string result = name + " of " + std::to_string(packSize) + " members (power " + std::to_string(combatPower) + ", "
                    + "loot " + std::to_string(loot)
                    + ", " + "damage " + std::to_string(damage) + ")";
    return result;
}

string Pack::applyEvent(Player &player) {
    int currCombatPower = combatPower;
    combatPower = 0;
    loot = 0;
    damage = 0;
    for (std::vector<std::unique_ptr<Monster> >::iterator it = pack.begin(); it != pack.end(); ++it) {
        it.operator*()->postBattle();
        combatPower += it.operator*()->getCombatPower();
        loot += it.operator*()->getLoot();
        damage += it.operator*()->getDamage();
    }
    if (currCombatPower < player.getCombatPower()) {
        player.wonBattle(getLoot());
        return getEncounterWonMessage(player, getLoot());
    } else {
        player.lostBattle(getDamage());
        return getEncounterLostMessage(player, getDamage());
    }
}

void Pack::postBattle() {
    combatPower = 0;
    loot = 0;
    damage = 0;
    for (std::vector<std::unique_ptr<Monster> >::iterator it = pack.begin(); it != pack.end(); ++it) {
        it.operator*()->postBattle();
        combatPower += it.operator*()->getCombatPower();
        loot += it.operator*()->getLoot();
        damage += it.operator*()->getDamage();
    }
}





