
#include "EventFactory.h"
#include <iostream>
#include "Event.h"
#include "Monster.h"


std::shared_ptr<Event> EventFactory::createEvent(const std::string &eventType) {
    if (eventType == "SolarEclipse") {
        return std::make_shared<SolarEclipse>(eventType);
    } else if (eventType == "PotionsMerchant") {
        return std::make_shared<PotionsMerchant>(eventType);
    } else if (eventType == "Snail") {
        return std::make_shared<Snail>();
    } else if (eventType == "Slime") {
        return std::make_shared<Slime>();
    } else if (eventType == "Balrog") {
        return std::make_shared<Balrog>();
    } else if (eventType == "Pack") {
        int size;
        std::cin >> size;
        return std::make_shared<Pack>(size);
    } else {
        // error
        return nullptr;
    }
}
