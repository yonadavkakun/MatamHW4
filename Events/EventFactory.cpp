#include "EventFactory.h"

std::unique_ptr<Event> EventFactory::createEvent(std::istream &eventsStream) {
    string eventType;
    eventsStream >> eventType;
    const static std::map<std::string, EventCreator> EventMap = {
        {string("SolarEclipse"), [&]() { return std::make_unique<SolarEclipse>(eventType); }},
        {string("PotionsMerchant"), [&]() { return std::make_unique<PotionsMerchant>(eventType); }},
        {string("Snail"), [&]() { return std::make_unique<Snail>(); }},
        {string("Slime"), [&]() { return std::make_unique<Slime>(); }},
        {string("Balrog"), [&]() { return std::make_unique<Balrog>(); }},
        {string("Pack"), [&]() { return std::make_unique<Pack>(eventsStream); }},
    };

    auto it = EventMap.find(eventType);
    if (it != EventMap.end()) {
        return it->second();
    }
    throw std::runtime_error("Invalid Events File");
}

