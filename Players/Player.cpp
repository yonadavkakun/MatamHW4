#include "Player.h"

#include <iostream>
#include <ostream>
#include <utility>
#include "../Utilities.h"


Player::Player(const string &playerName,
               std::unique_ptr<Stats> playerStats,
               std::unique_ptr<Job> jobType,
               std::unique_ptr<Character> charType): name(playerName),
                                                     stats(std::move(playerStats)),
                                                     job(std::move(jobType)),
                                                     character(std::move(charType)) {
}

int Player::getCoins() const {
        return stats->getCoins();
}

string Player::getJob() const {
        return job->getJob();
}


string Player::getDescription() const {
        string result = name + ", " + getJob() + " with "
                        + getCharacter() + " character "
                        + "(level " + std::to_string(getLevel()) + ", force "
                        + std::to_string(getForce()) + ")";
        return result;
}

int Player::getForce() const {
        return stats->getForce();
}

int Player::getLevel() const {
        return stats->getLevel();
}

string Player::getName() const {
        return name;
}

int Player::getHealthPoints() const {
        return stats->getHealthPoints();
}

int Player::getMaxHealthPoints() const {
        return stats->getMaxHealthPoints();
}

string Player::getCharacter() const {
        return character->getCharacter();
}

void Player::buySinglePotion() const {
        stats->setCoins(-5);
        stats->setHealthPoints(10);
}


int Player::getCombatPower() const {
        return job->getCombatPower(*stats);
}

void Player::wonBattle(int loot) const {
        job->wonBattle(loot, *stats);
}

void Player::lostBattle(int damage) const {
        job->lostBattle(damage, *stats);
}

string Player::solarEclipseEffect() const {
        return getSolarEclipseMessage(*this, job->solarEclipseEffect(*stats));
}

bool Player::operator<(const Player &other) const {
        if (stats->getLevel() != other.stats->getLevel()) {
                return stats->getLevel() > other.stats->getLevel();
        }
        if (stats->getCoins() != other.stats->getCoins()) {
                return stats->getCoins() > other.stats->getCoins();
        }
        return this->name < other.name;
}

string Player::potionPurchase() {
        return character->potionPurchase(*this);
}

