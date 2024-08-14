#pragma once
#include <string>

class Player;


class Character {
 std::string character;

public:
 Character(const std::string &characterType);

 /**
  * potion purchasing mechanics take place in accordance with character
  *
  * @param player
  * @return outcome (number of potions purchased in current event)
  */
 virtual std::string potionPurchase(Player &player) =0;

 /**
  * returns the characterType of a player
  * @return characterType
  */
 std::string getCharacter();

 /**
  * d`tor for character
  */
 virtual ~Character() = default;
};

class Responsible : public Character {
public:
 /**
  * c`tor
  * @param characterType
  */
 Responsible(const std::string &characterType);

 /**
  * purchases potions untill player has full HP
  * @param player
  * @return outcome (number of potions purchased in current event)
  */
 std::string potionPurchase(Player &player) override;

 /**
  * d`tor
  */
 ~Responsible() override = default;
};

class RiskTaking : public Character {
public:
 /**
  * c`tor
  * @param characterType
  */
 RiskTaking(const std::string &characterType);

 /**
  * if HP is less than 50, purchases a single potion
  * @param player
  * @return outcome (number of potions purchased in current event
  */
 std::string potionPurchase(Player &player) override;

 /**
  * d`tor
  */
 ~RiskTaking() override = default;
};
