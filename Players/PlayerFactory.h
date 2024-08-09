#pragma once


#include "Player.h"
#include <map>
#include <memory>
#include <string>


class PlayerFactory {
    //std::map<std::string, std::unique_ptr<Player>()> playersMap;
public:
    static std::shared_ptr<Player> createPlayer(const std::string &playerName,
                                                const std::string &playerJob, const std::string &playerCharacter);
};
