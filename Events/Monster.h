#pragma once
#include "Event.h"

class Monster : public Event {
protected:
    int combatPower = 0;
    int loot = 0;
    int damage = 0;

public:
    /**
     * c'tor
     *
     */
    Monster(const string &monsterName);

    /**
     * Gets the Description of the Monster
     *
     * @return - the Description of the Monster
    */
    virtual string getDescription() const override;

    /**
     * applying the battle on player
     *
     * @param player
     * @return - combat outcome
    */
    virtual string applyEvent(Player &player) override;

    virtual void postBattle();

    /**
     * Gets the Loot of the Monster
     *
     * @return - the Loot of the Monster
    */
    int getLoot() const;

    /**
     * Gets the Damage of the Monster
     *
     * @return - the Damage of the Monster
    */
    int getDamage() const;

    /**
     * Gets the CombatPower of the Monster
     *
     * @return - the CombatPower of the Monster
    */
    int getCombatPower() const;

    /**
     * d'tor
     *
     */
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
    static const int MIN_PACK_SIZE = 2;
    int packSize = 0;
    std::vector<std::unique_ptr<Monster> > pack;

public:
    Pack(std::istream &eventsStream);

    string applyEvent(Player &player) override;

    void postBattle() override;


    string getDescription() const override;

    ~Pack() override = default;
};
