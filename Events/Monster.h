#pragma once
#include "Event.h"


class Monster : public Event {
    int combatPower;
    int loot;
    int damage;

public:
    Monster();
    string getDescription() const override;
    void applyEvent() override;
    ~Monster();
};

class Snail : public Monster {
public:
    Snail();
    ~Snail();
};

class Slime : public Monster {
public:
    Slime();
    ~Slime();
};

class Balrog : public Monster {
    int extraPoints;

public:
    Balrog();
    void applyEvent() override;
    ~Balrog();

};

class Pack : public Monster {
    int packSize;
    std::vector<std::unique_ptr<Event> > pack;

public:
    Pack(int packSize);
    void applyEvent() override;
    ~Pack();
};
