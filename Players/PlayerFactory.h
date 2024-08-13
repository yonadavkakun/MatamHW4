
#pragma once
#include "JobFactory.h"
#include "CharacterFactory.h"
#include "Player.h"

class PlayerFactory {
public:
    static std::shared_ptr<Player> createPlayer(std::istream &playersStream);
};
