
#pragma once
#include "JobFactory.h"
#include "CharacterFactory.h"
#include "Player.h"

class PlayerFactory {
public:
    static std::shared_ptr<Player> createPlayer(const std::string &playerName,
                                                const std::string &playerJob, const std::string &playerCharacter) {
        std::shared_ptr<Stats> stats;
        auto job = JobFactory::createJob(playerJob, stats);
        auto character = CharacterFactory::createCharacter(playerCharacter);
        return std::make_shared<Player>(playerName, job, character);
    }
};
