#include "Player.h"
#include <ostream>
#include <utility>
#include "../Utilities.h"


Player::Player(const string &playerName,
               std::shared_ptr<Job> jobType,
               std::shared_ptr<Character> charType): name(playerName),
                                                     stats(std::make_shared<Stats>()),
                                                     job(jobType),
                                                     character(charType) {
}

int Player::getCoins() const {
        return stats->getCoins();
}

string Player::getJob() const {
        return job->getJob();
}


string Player::getDescription() const {
        string result = name + ", " + getJob() + " with "
                        + getCharacter() + "character"
                        + "(level " + std::to_string(getLevel()) + ", force"
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

void Player::buySinglePotion() {
        stats->setCoins(-5);
        stats->setHealthPoints(10);
}


int Player::getCombatPower() const {
        return job->getCombatPower(stats);
}

void Player::wonBattle(int loot) {
        job->wonBattle(loot, stats);
}

void Player::lostBattle(int damage) {
        job->lostBattle(-damage, stats);
}

string Player::solarEclipseEffect() {
        job->solarEclipseEffect(stats);
        return getSolarEclipseMessage(*this, -1);
}

bool Player::operator<(const Player &other) const {
        if (stats->getLevel() != other.stats->getLevel())
                return stats->getLevel() < other.stats->getLevel();
        if (stats->getCoins() != other.stats->getCoins())
                return stats->getCoins() < other.stats->getCoins();
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

