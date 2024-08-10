#include "Player.h"

#include <ostream>
#include <utility>

Player::Player(const string &playerName, std::shared_ptr<Character> charType) : name(playerName),
        level(STARTING_LEVEL),
        force(STARTING_FORCE),
        currHealthPoints(STARTING_FORCE),
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

string Player::getCharacter() const {
        return character->getCharacter();
}

int Player::getCombatPower() const {
        return force + level;
}

void Player::wonBattle(int loot) {
        coins += loot;
        level++;
}

void Player::lostBattle(int damage) {
        currHealthPoints -= damage;
}

void Player::solarEclipseEffect() {
        force--;
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
