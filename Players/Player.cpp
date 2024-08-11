#include "Player.h"
#include <ostream>
#include <utility>

#include "../Events/Monster.h"

Player::Player(const string &playerName, std::shared_ptr<Character> charType) : name(playerName),
        level(STARTING_LEVEL),
        force(STARTING_FORCE),
        currHealthPoints(MAX_HP),
        maxHealthPoints(MAX_HP),
        coins(STARTING_COINS),
        character(std::move(charType)) {
}

int Player::getCoins() const {
        return coins;
}

string Player::getDescription() const {
        string result = name + ", " + this->getJob() + " with "
                        + this->getCharacter() + "character"
                        + "(level " + std::to_string(this->getLevel()) + ", force"
                        + std::to_string(this->getForce()) + ")";
        return result;
}

int Player::getForce() const {
        return force;
}

int Player::getLevel() const {
        return level;
}

string Player::getName() const {
        return name;
}

int Player::getHealthPoints() const {
        return currHealthPoints;
}

int Player::getMaxHealthPoints() const {
        return maxHealthPoints;
}

string Player::getCharacter() const {
        return character->getCharacter();
}

void Player::buySinglePotion() {
        coins -= 5;
        currHealthPoints += 10;
}


int Player::getCombatPower() const {
        return force + level;
}

void Player::wonBattle(const Monster &monsterType) {
        coins += monsterType.getLoot();
        level++;
}

void Player::lostBattle(const Monster &monsterType) {
        currHealthPoints -= monsterType.getDamage();
}

string Player::solarEclipseEffect() {
        force--;
        return getSolarEclipseMessage(*this, -1);
}

bool Player::operator<(const Player &other) const {
        if (this->level != other.level)
                return this->level < other.level;
        if (this->coins != other.coins)
                return this->coins < other.coins;
        return this->name > other.name;
}

/*
std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << player.getDescription() << std::endl;
        return os;
}
*/

string Player::potionPurchase() {
        return character->potionPurchase(*this);
}

