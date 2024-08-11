#pragma once
#include "Event.h"


class Monster : public Event {
protected:
    int combatPower;
    int loot;
    int damage;

public:
    Monster(const string &monsterName);

    string getDescription() const override;

    string applyEvent(Player &player) override;

    int getLoot() const override;

    int getDamage() const override;

    int getCombatPower() const override;

    virtual ~Monster() = default;
};

class Snail : public Monster {
public:
    Snail();

    ~Snail() override = default;
};

class Slime : public Monster {
public:
    Slime();

    ~Slime() override = default;
};

class Balrog : public Monster {
public:
    Balrog();

    string applyEvent(Player &player) override;

    void postBattle() override;

    ~Balrog() override = default;
};

class Pack : public Monster {
    int packSize;
    std::vector<std::shared_ptr<Event> > pack;

public:
    Pack(int packSize);

    string applyEvent(Player &player) override;

    string getDescription() const override;

    ~Pack() override = default;
};
