#include "PlayerFactory.h"

std::shared_ptr<Player> PlayerFactory::createPlayer(std::istream &playersStream) {
    string playerName, playerJob, playerCharacter;
    playersStream >> playerName >> playerJob >> playerCharacter;
    int nameSize = 0;
    for (char c: playerName) {
        if (!std::isalpha(c)) {
            throw std::runtime_error("Invalid Players File");
        }
        nameSize++;
    }
    if (nameSize > 15 || nameSize < 3) {
        throw std::runtime_error("Invalid Players File");
    }
    std::shared_ptr<Stats> stats = std::make_shared<Stats>();
    auto job = JobFactory::createJob(playerJob, stats);
    auto character = CharacterFactory::createCharacter(playerCharacter);
    return std::make_shared<Player>(playerName, stats, job, character);
}
