#pragma once

class Character {
    string character;

public:
    Character(string character);

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