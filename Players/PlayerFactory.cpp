#include "PlayerFactory.h"

std::unique_ptr<Player> PlayerFactory::createPlayer(std::istream &playersStream) {
    string playerName, playerJob, playerCharacter;
    playersStream >> playerName >> playerJob >> playerCharacter;
    int nameSize = playerName.size();
    if (nameSize > MAX_NAME_SIZE || nameSize < MIN_NAME_SIZE) {
        throw std::runtime_error("Invalid Players File");
    }
    std::unique_ptr<Stats> stats = std::make_unique<Stats>();
    auto job = JobFactory::createJob(playerJob, stats.get());
    auto character = CharacterFactory::createCharacter(playerCharacter);
    return std::make_unique<Player>(playerName, std::move(stats), std::move(job), std::move(character));
}
