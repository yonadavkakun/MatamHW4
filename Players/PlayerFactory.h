#pragma once


#include "Player.h"
#include <map>
#include <memory>
#include <string>


class PlayerFactory {
    //std::map<std::string, std::unique_ptr<Player>()> playersMap;
public:
    static std::unique_ptr<Player> createPlayer(const std::string &playerType);
};
