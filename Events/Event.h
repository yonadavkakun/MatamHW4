#pragma once
#include <string>
using std::string;
#include <memory>
#include <vector>
#include "../Players/Player.h"
//class Player;

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
    virtual string applyEvent(Player &player) =0;

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
    * c'tor
    *
    *@param eventName
    */
    Event(const string &eventName);

    virtual ~Event() = default;
};

class SolarEclipse : public Event {
public:
    SolarEclipse(const string &eventName);

    string applyEvent(Player &player) override;

    ~SolarEclipse() override = default;
};

class PotionsMerchant : public Event {
public:
    PotionsMerchant(const string &eventName);

    string applyEvent(Player &player) override;

    ~PotionsMerchant() override = default;
};
