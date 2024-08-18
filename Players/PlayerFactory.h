
#pragma once
#include "JobFactory.h"
#include "CharacterFactory.h"
#include "Player.h"

class PlayerFactory {
    static const int MIN_NAME_SIZE = 3;
    static const int MAX_NAME_SIZE = 15;

public:
    /**
     * creates a unique_ptr to a player in playersStream
     * throws an exception if a player is invalid
     *
     * @param playersStream
     * @return unique_ptr<Player> player
     */
    static std::unique_ptr<Player> createPlayer(std::istream &playersStream);
};
