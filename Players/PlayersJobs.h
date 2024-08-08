#pragma once
#include "Player.h"

class Warrior : public Player {
public:
    Warrior(const std::string &playerName,
        const std::string &playerJob, const std::string &playerCharacter);
};

class Archer : public Player {
public:
    Archer(const std::string &playerName,
        const std::string &playerJob, const std::string &playerCharacter);
};

class Magician : public Player {
public:
    Magician(const std::string &playerName,
        const std::string &playerJob, const std::string &playerCharacter);
};
