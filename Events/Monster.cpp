# include "Monster.h"
#include "EventFactory.h"
#include <iostream>

Monster::Monster(const string &monsterName) : Event(monsterName) {
}


string Monster::getDescription() const {
    string result = name + "(power " + std::to_string(combatPower) + ", "
                    + "loot " + std::to_string(loot)
                    + ", " + "damage " + std::to_string(damage) + ")";
    return result;
}

Snail::Snail(): Monster("snail") {
    combatPower = 5;
    loot = 2;
    damage = 10;
}

Slime::Slime(): Monster("Slime") {
    combatPower = 12;
    loot = 5;
    damage = 25;
}

Balrog::Balrog(): Monster("Balrog"), extraPoints(0) {
    combatPower = 15;
    loot = 100;
    damage = 9001;
}

Pack::Pack(int packSize) : Monster("Pack"), packSize(packSize) {
    for (int i = 0; i < packSize; i++) {
        string packMember;
        std::cin >> packMember;
        pack.push_back(EventFactory::createEvent(packMember));
    }
}



