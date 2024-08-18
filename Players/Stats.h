#pragma once


class Stats {
 static const int STARTING_LEVEL = 1;
 static const int STARTING_FORCE = 5;
 static const int STARTING_CURR_HP = 100;
 static const int STARTING_MAX_HP = 100;
 static const int STARTING_COINS = 10;
 int level;
 int force;
 int currHealthPoints;
 int maxHealthPoints;
 int coins;

public:
 /**
  * Stats c'tor
  *
  * by defult: level=1, force=5, currHP=maxHP=100, coins=10.
 */
 Stats();

 /**
  * Gets the current level of the player
  *
  * @return - level of the player
 */
 int getLevel() const;

 /**
  * sets the current level of the player
  *
 */
 void setLevel(int amount);

 /**
  * Gets the of force the player has
  *
  * @return - force points of the player
 */
 int getForce() const;

 /**
  * sets the of force the player has
  *
  * @return - the change in the force points
 */
 int setForce(int amount);

 /**
  * Gets the amount of health points the player currently has
  *
  * @return - health points of the player
 */
 int getHealthPoints() const;

 /**
 * sets the amount of health points the player currently has
 *
*/
 void setHealthPoints(int amount);

 /**
  * Gets the Max health points of the player
  *
  * @return - max health points of the player
 */
 int getMaxHealthPoints() const;

 /**
 * sets the Max health points of the player
 *
*/
 void setMaxHealthPoints(int amount);

 /**
  * Gets the amount of coins the player has
  *
  * @return - coins of the player
 */
 int getCoins() const;

 /**
 * sets the amount of coins the player has
 *
*/
 void setCoins(int amount);
};
