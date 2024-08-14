
#pragma once
#include "JobFactory.h"
#include "CharacterFactory.h"
#include "Player.h"

class PlayerFactory {
public:
    /**
     * creates a shared_ptr to a player in playersStream
     * throws an exception if a player is invalid
     *
     * @param playersStream
     * @return shared_ptr<Player> player
     */
    static std::shared_ptr<Player> createPlayer(std::istream &playersStream);
};
