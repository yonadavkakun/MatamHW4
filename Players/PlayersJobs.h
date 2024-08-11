#pragma once
#include "Player.h"

class Warrior : public Player {
public:
    Warrior(const std::string &playerName, std::shared_ptr<Character> playerCharacter);

    string getJob() const override;

    int getCombatPower() const override;

    void wonBattle(const Monster &monsterType) override;
};

class Archer : public Player {
public:
    Archer(const std::string &playerName, std::shared_ptr<Character> playerCharacter);

    string getJob() const override;
};

class Magician : public Player {
public:
    Magician(const std::string &playerName, std::shared_ptr<Character> playerCharacter);

    string getJob() const override;

    string solarEclipseEffect() override;
};
