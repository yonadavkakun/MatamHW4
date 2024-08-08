
#include "EventFactory.h"
#include <iostream>
#include "Event.h"
#include "Monster.h"


std::unique_ptr<Event> EventFactory::createEvent(const std::string &eventType) {
    switch (eventType) {
        case "SolarEclipse":
            return std::make_unique<SolarEclipse>();
            break;
        case "PotionsMerchant":
            return std::make_unique<PotionsMerchant>();
            break;
        case "Snail":
            return std::make_unique<Snail>();
            break;
        case "Slime":
            return std::make_unique<Slime>();
            break;
        case "Balrog":
            return std::make_unique<Balrog>();
            break;
        case "Pack":
            int size;
            std::cin >> size;
            return std::make_unique<Pack>(size);
            break;
        default:
            //error
            return nullptr;
            break;
    }
}
