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
}

void Stats::setForce(int amount) {
    force += amount;
}

void Stats::setLevel(int amount) {
    level += amount;
}

void Stats::setHealthPoints(int amount) {
    currHealthPoints += amount;
    if (currHealthPoints < 0) {
        currHealthPoints = 0;
    }
}

void Stats::setMaxHealthPoints(int amount) {
    maxHealthPoints += amount;
}


