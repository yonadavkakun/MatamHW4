
#pragma once

#include <memory>
#include <vector>

#include "../Players/Player.h"

class Event {
protected:
    string name;

public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const;

    virtual void applyEvent() =0;

    virtual ~Event() =0;
};

class SolarEclipse : public Event {
public:
    SolarEclipse();

    void applyEvent() override;

    ~SolarEclipse() = default;
};

class PotionsMerchant : public Event {
public:
    PotionsMerchant();

    void applyEvent() override;

    ~PotionsMerchant() = default;
};
