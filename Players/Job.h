#pragma once
#include <memory>
#include <string>

#include "Stats.h"
using std::string;

class Job {
protected:
 string jobName;

public:
 /**
  * c`tor
  * @param jobName
  */
 Job(const string &jobName);

 /**
  * returns the job of the player
  * @return jobType
  */
 virtual string getJob() const =0;

 /**
  * the player experiences a solar eclipse, appropriate effects take place
  * @param playerStats
  * @return -1 (force-increment as defined in assignment)
  */
 virtual int solarEclipseEffect(Stats &playerStats);

 /**
 * Gets the CombatPower of the player as int
 *
 * @return - CombatPower of the player
 */
 virtual int getCombatPower(Stats &playerStats) const;

 /**
 * the player won, he gets the loot and level up
 *
 *@param loot
 */
 virtual void wonBattle(int loot, Stats &playerStats);

 /**
* the player lost, he lost HP as the monster damage
*
*@param damage
*/
 virtual void lostBattle(int damage, Stats &playerStats);

 virtual ~Job() = default;
};

//Warrior
class Warrior : public Job {
public:
 /**
  * c`tor
  * @param jobName
  * @param playerStats
  */
 Warrior(const string &jobName, Stats &playerStats);

 /**
  * combatPower getter function
  * @param playerStats
  * @return combatPower
  */
 int getCombatPower(Stats &playerStats) const override;

 /**
  * HP is dropped by 10. level goes up by 1. coins are increased by monster's loot
  * @param loot
  * @param playerStats
  */
 void wonBattle(int loot, Stats &playerStats) override;

 /**
  * job getter
  * @return jobType
  */
 string getJob() const override;

 /**
  * d`tor
  */
 ~Warrior() override = default;
};

//Archer
class Archer : public Job {
public:
 /**
  * c`tor
  * @param jobName
  * @param playerStats
  */
 Archer(const string &jobName, Stats &playerStats);

 /**
  * job getter
  * @return jobType
  */
 string getJob() const override;

 /**
  * d`tor
  */
 ~Archer() override = default;
};

//Magician
class Magician : public Job {
public:
 /**
  * c`tor
  * @param jobName
  */
 Magician(const string &jobName);

 /**
  * job getter
  * @return jobType
  */
 string getJob() const override;

 /**
  * magician's solar eclipse effect take place. force is increased by 1.
  * @param playerStats
  * @return 1 (force-increment as defined in assignment)
  */
 int solarEclipseEffect(Stats &playerStats) override;

 /**
  * c`tor
  */
 ~Magician() override = default;
};

