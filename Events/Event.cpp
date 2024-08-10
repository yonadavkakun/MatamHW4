# include "Event.h"

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

void SolarEclipse::applyEvent(Player &player) {
    player.solarEclipseEffect();
}

//PotionsMerchant
PotionsMerchant::PotionsMerchant(const string &eventName) : Event(eventName) {
    name = "PotionsMerchant";
}
