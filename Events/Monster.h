#pragma once
#include "Event.h"


class Monster : public Event {
protected:
    int combatPower;
    int loot;
    int damage;

public:
    Monster()=default;

    string getDescription() const override;

    void applyEvent() override;

    virtual ~Monster();
};

class Snail : public Monster {
public:
    Snail();

    ~Snail()override=default;
};

class Slime : public Monster {
public:
    Slime();

    ~Slime()override=default;
};

class Balrog : public Monster {
    int extraPoints;

public:
    Balrog();

    void applyEvent() override;

    ~Balrog()override=default;
};

class Pack : public Monster {
    int packSize;
    std::vector<std::unique_ptr<Event> > pack;

public:
    Pack(int packSize);

    void applyEvent() override;

    ~Pack()override;
};
