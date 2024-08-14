# include "Event.h"

#include <stdexcept>

//Event
Event::Event(const string &eventName) : name(eventName) {
}

string Event::getDescription() const {
    return name;
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


