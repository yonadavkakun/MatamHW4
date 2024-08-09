#pragma once
#include <string>


class Character {
    std::string character;

public:
    Character(const std::string &characterType);

    virtual void purchasesPotions();

    std::string getCharacter();

    virtual ~Character() = default;
};

class Responsible : public Character {
public:
    Responsible(const std::string &characterType);

    void purchasesPotions() override;

    ~Responsible() override;
};

class RiskTaking : public Character {
public:
    RiskTaking(const std::string &characterType);

    void purchasesPotions() override;

    ~RiskTaking() override;
};
