#include "PlayerFactory.h"

std::shared_ptr<Player> PlayerFactory::createPlayer(const std::string &playerName,
                                                    const std::string &playerJob,
                                                    const std::string &playerCharacter) {
    std::shared_ptr<Stats> stats = std::make_shared<Stats>();
    auto job = JobFactory::createJob(playerJob, stats);
    auto character = CharacterFactory::createCharacter(playerCharacter);
    return std::make_shared<Player>(playerName, stats, job, character);
}
