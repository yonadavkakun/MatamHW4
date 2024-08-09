#include "PlayerFactory.h"

#include <iostream>

#include "PlayersJobs.h"


std::shared_ptr<Player> PlayerFactory::createPlayer(const std::string &playerName,
                                                    const std::string &playerJob, const std::string &playerCharacter) {
    std::shared_ptr<Character> character;

    if (playerCharacter == "Responsible") {
        character = std::make_shared<Responsible>(playerCharacter);
    } else if (playerCharacter == "RiskTaking") {
        character = std::make_shared<RiskTaking>(playerCharacter);
    }

    if (playerJob == "Warrior") {
        return std::make_shared<Warrior>(playerName, character);
    } else if (playerJob == "Archer") {
        return std::make_shared<Archer>(playerName, character);
    } else if (playerJob == "Magician") {
        return std::make_shared<Magician>(playerName, character);
    } else {
        // error
        return nullptr;
    }
}
