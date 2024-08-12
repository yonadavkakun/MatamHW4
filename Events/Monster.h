#pragma once
#include "Event.h"

//class Player;


class Monster : public Event {
protected:
    int combatPower;
    int loot;
    int damage;

public:
    Monster(const string &monsterName);

    virtual string getDescription() const override;

    virtual string applyEvent(Player &player) override;

    virtual void postBattle();

    int getLoot() const override;

    int getDamage() const override;

    int getCombatPower() const override;

    virtual ~Monster() override = default;
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
    int packSize = 0;
    std::vector<std::shared_ptr<Monster> > pack;

public:
    Pack(std::istream &eventsStream);

    string applyEvent(Player &player) override;

    string getDescription() const override;

    ~Pack() override = default;
};
