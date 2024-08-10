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

    void applyEvent(Player &player) override;

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
    int extraPoints;

public:
    Balrog();

    void applyEvent(Player &player) override;

    ~Balrog() override = default;
};

class Pack : public Monster {
    int packSize;
    std::vector<std::shared_ptr<Event> > pack;

public:
    Pack(int packSize);

    void applyEvent(Player &player) override;

    ~Pack() override = default;
};
