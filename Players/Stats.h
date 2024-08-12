#pragma once


class Stats {
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
  * @return - level of the player
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
     * @return - force points of the player
    */
 void setForce(int amount);

 /**
  * Gets the amount of health points the player currently has
  *
  * @return - health points of the player
 */
 int getHealthPoints() const;

 /**
 * sets the amount of health points the player currently has
 *
 * @return - health points of the player
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
 * @return - max health points of the player
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
 * @return - coins of the player
*/
 void setCoins(int amount);
};
