#include "Factory.h"

#include <iostream>

#include "Events/Monster.h"


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

std::unique_ptr<Player> PlayerFactory::createPlayer(const std::string &playerType) {
    switch (playerType) {
        case "Warrior":
            return std::make_unique<Warrior>();
            break;
        case "Archer":
            return std::make_unique<Archer>();
            break;
        case "Magician":
            return std::make_unique<Magician>();
            break;
        default:
            //error
            return nullptr;
            break;
    }
}
