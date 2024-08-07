#pragma once


class Character {
    std::string character;

public:
    Character(std::string character);

    virtual void purchasesPotions();
};

class Responsible : public Character {
public:
    void purchasesPotions() override;
};

class RiskTaking : public Character {
public:
    void purchasesPotions() override;
};
