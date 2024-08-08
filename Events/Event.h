
#pragma once

#include <memory>
#include <vector>

#include "../Players/Player.h"

class Event {
    string name;

public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const =0;

    virtual void applyEvent() =0;
};

class SolarEclipse {
public:
    SolarEclipse();
};

class PotionsMerchant {
public:
    PotionsMerchant();
};

class Snail {
public:
    Snail();
};

class Slime {
public:
    Slime();
};

class Balrog {
    int extraPoints;

public:
    Balrog();
};

class Pack {
    int packSize;
    std::vector<std::unique_ptr<Event> > pack;

public:
    Pack(int packSize);
};
