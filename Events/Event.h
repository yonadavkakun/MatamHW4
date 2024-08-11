
#pragma once

#include <memory>
#include <vector>

#include "../Players/Player.h"

class Event {
protected:
    string name;

public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const;

    /**
     * applying the event on the player - pure virtual
     *
     * @param player
    */
    virtual void applyEvent(Player &player) =0;

    /**
    * while not Monster throw exception
    *
    */
    virtual int getCombatPower() const;

    /**
    * while not Monster throw exception
    *
    */
    virtual int getLoot() const;

    /**
    * while not Monster throw exception
    *
    */
    virtual int getDamage() const;

    /**
        * while not Monster throw exception
        *
        */
    virtual void postBattle() =0;

    /**
    * c'tor
    *
    *@param eventName
    */
    Event(const string &eventName);
};

class SolarEclipse : public Event {
public:
    SolarEclipse(const string &eventName);

    void applyEvent(Player &player) override;

    ~SolarEclipse() = default;
};

class PotionsMerchant : public Event {
public:
    PotionsMerchant(const string &eventName);

    void applyEvent(Player &player) override;

    ~PotionsMerchant() = default;
};
