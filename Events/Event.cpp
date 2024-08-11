# include "Event.h"

#include <stdexcept>

//Event
Event::Event(const string &eventName) : name(eventName) {
}

string Event::getDescription() const {
    return name;
}

int Event::getDamage() const {
    throw std::runtime_error("trying to add nonMonster to pack");
}

int Event::getLoot() const {
    throw std::runtime_error("trying to add nonMonster to pack");
}

int Event::getCombatPower() const {
    throw std::runtime_error("trying to add nonMonster to pack");
}

void Event::postBattle() {
    return;
}


//SolarEclipse
SolarEclipse::SolarEclipse(const string &eventName): Event(eventName) {
    name = "SolarEclipse";
}

string SolarEclipse::applyEvent(Player &player) {
    return player.solarEclipseEffect();
}

//PotionsMerchant
PotionsMerchant::PotionsMerchant(const string &eventName) : Event(eventName) {
    name = "PotionsMerchant";
}

string PotionsMerchant::applyEvent(Player &player) {
    return player.potionPurchase();
}


