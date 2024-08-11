#pragma once
#include <string>

class Player;


class Character {
    std::string character;

public:
    Character(const std::string &characterType);

    virtual std::string potionPurchase(Player &player) =0;

    std::string getCharacter();

    virtual ~Character() = default;
};

class Responsible : public Character {
public:
    Responsible(const std::string &characterType);

    std::string potionPurchase(Player &player) override;

    ~Responsible() override = default;
};

class RiskTaking : public Character {
public:
    RiskTaking(const std::string &characterType);

    std::string potionPurchase(Player &player) override;

    ~RiskTaking() override = default;
};
