#include "PlayerFactory.h"

#include <iostream>


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
