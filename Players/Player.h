
#pragma once
#include <memory>
#include "../Utilities.h"
#include "Character.h"
#include <string>

class Monster;
using std::string;


class Player {
protected:
 string name;
 int level;
 int force;
 int currHealthPoints;
 int maxHealthPoints;
 int coins;
 std::shared_ptr<Character> character;

public:
 static const int MAX_HP = 100;
 static const int MAX_LEVEL = 10;
 static const int STARTING_LEVEL = 1;
 static const int STARTING_FORCE = 5;
 static const int STARTING_COINS = 10;

 //c'tor
 Player(const string &playerName, std::shared_ptr<Character> charType);


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
 virtual string getJob() const =0;

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
 virtual int getCombatPower() const;

 /**
* the player won, he gets the loot and level up
*
*@param monsterType
*/
 virtual void wonBattle(const Monster &monsterType);

 /**
* the player lost, he lost HP as the monster damage
*
*@param monsterType
*/
 virtual void lostBattle(const Monster &monsterType);


 virtual string solarEclipseEffect();

 /**
* operator<<, prints the player description
*
*@param os, player
*/
 // friend std::ostream &operator<<(std::ostream &os, const Player &player);

 /**
* operator<, less than, return true if other is greater than player
*
*@param other
*/
 bool operator<(const Player &other) const;

 string potionPurchase();
};


