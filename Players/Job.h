#pragma once
#include <memory>
#include <string>

#include "Stats.h"
using std::string;

class Job {
protected:
    string jobName;

public:
    Job(const string &jobName);

    virtual string getJob() const =0;

    virtual void solarEclipseEffect(std::shared_ptr<Stats> playerStats);

    /**
    * Gets the CombatPower of the player as int
    *
    * @return - CombatPower of the player
    */
    virtual int getCombatPower(std::shared_ptr<Stats> playerStats) const;

    /**
    * the player won, he gets the loot and level up
    *
    *@param loot
    */
    virtual void wonBattle(int loot, std::shared_ptr<Stats> playerStats);

    /**
   * the player lost, he lost HP as the monster damage
   *
   *@param damage
   */
    virtual void lostBattle(int damage, std::shared_ptr<Stats> playerStats);

    virtual ~Job() = default;
};

//Warrior
class Warrior : public Job {
public:
    Warrior(const string &jobName, std::shared_ptr<Stats> playerStats);

    int getCombatPower(std::shared_ptr<Stats> playerStats) const override;

    void wonBattle(int loot, std::shared_ptr<Stats> playerStats) override;

    string getJob() const override;

    ~Warrior() override = default;
};

//Archer
class Archer : public Job {
public:
    Archer(const string &jobName, std::shared_ptr<Stats> playerStats);

    string getJob() const override;

    ~Archer() override = default;
};

//Magician
class Magician : public Job {
public:
    Magician(const string &jobName);

    string getJob() const override;

    void solarEclipseEffect(std::shared_ptr<Stats> playerStats) override;

    ~Magician() override = default;
};

