#pragma once
#include <memory>
#include "Character.h"
#include <string>

#include "Job.h"
#include "Stats.h"
using std::string;


class Player {
protected:
 string name;
 std::shared_ptr<Stats> stats;
 std::shared_ptr<Job> job;
 std::shared_ptr<Character> character;

public:
 //c'tor
 Player(const string &playerName, std::shared_ptr<Job> jobType, std::shared_ptr<Character> charType);


 /**
  * Gets the description of the player
  *
  * @return - description of the player
 */
 string getDescription() const;

 /**
  * Gets the name of the player
  *
  * @return - name of the player
 */
 string getName() const;

 /**
  * Gets the current level of the player
  *
  * @return - level of the player
 */
 int getLevel() const;

 /**
  * Gets the of force the player has
  *
  * @return - force points of the player
 */
 int getForce() const;

 /**
  * Gets the amount of health points the player currently has
  *
  * @return - health points of the player
 */
 int getHealthPoints() const;

 /**
  * Gets the Max health points of the player
  *
  * @return - max health points of the player
 */
 int getMaxHealthPoints() const;

 /**
  * Gets the amount of coins the player has
  *
  * @return - coins of the player
 */
 int getCoins() const;

 /**
  * Gets the job of the player as a string, pure virtual
  *
  * @return - job of the player
 */
 string getJob() const;

 /**
 * Gets the character of the player as a string
 *
 * @return - character of the player
*/
 string getCharacter() const;

 /**
* buy a potion for the player, 5 coins for 10 HP
*
*/
 void buySinglePotion();

 /**
* Gets the CombatPower of the player as int
*
* @return - CombatPower of the player
*/
 int getCombatPower() const;

 /**
* the player won, he gets the loot and level up
*
*@param monsterType
*/
 void wonBattle(int loot);

 /**
* the player lost, he lost HP as the monster damage
*
*@param monsterType
*/
 void lostBattle(int damage);


 string solarEclipseEffect();


 /**
* operator<, less than, return true if other is greater than player
*
*@param other
*/
 bool operator<(const Player &other) const;

 string potionPurchase();
};


