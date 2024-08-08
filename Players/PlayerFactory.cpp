#include "PlayerFactory.h"

#include <iostream>

#include "PlayersJobs.h"


std::unique_ptr<Player> PlayerFactory::createPlayer(const std::string &playerName,
                const std::string &playerJob, const std::string &playerCharacter) {
    switch (playerName) {
        case "Warrior":
            return std::make_unique<Warrior>(playerName, playerJob, playerCharacter);
            break;
        case "Archer":
            return std::make_unique<Archer>(playerName, playerJob, playerCharacter);
            break;
        case "Magician":
            return std::make_unique<Magician>(playerName, playerJob, playerCharacter);
            break;
        default:
            //error
            return nullptr;
            break;
    }
}
