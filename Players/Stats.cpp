#include "Stats.h"

Stats::Stats() : level(1), force(5), currHealthPoints(100), maxHealthPoints(100), coins(10) {
}

int Stats::getCoins() const {
    return coins;
}

int Stats::getForce() const {
    return force;
}

int Stats::getLevel() const {
    return level;
}

int Stats::getHealthPoints() const {
    return currHealthPoints;
}

int Stats::getMaxHealthPoints() const {
    return maxHealthPoints;
}

void Stats::setCoins(int amount) {
    coins += amount;
    if (coins < 0) {
        coins = 0;
    }
}

int Stats::setForce(int amount) {
    if (force <= 0) {
        force = 0;
        return 0;
    }
    force += amount;
    return amount;
}

void Stats::setLevel(int amount) {
    level += amount;
    if (level < 0) {
        level = 0;
    }
}

void Stats::setHealthPoints(int amount) {
    currHealthPoints += amount;
    if (currHealthPoints < 0) {
        currHealthPoints = 0;
    }
}

void Stats::setMaxHealthPoints(int amount) {
    maxHealthPoints += amount;
    if (maxHealthPoints < 0) {
        maxHealthPoints = 0;
    }
}


