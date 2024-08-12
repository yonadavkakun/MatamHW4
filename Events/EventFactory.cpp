#include "EventFactory.h"

std::shared_ptr<Event> EventFactory::createEvent(const std::string &eventType) {
    const static std::map<std::string, EventCreator> EventMap = {
        {string("SolarEclipse"), [&]() { return std::make_shared<SolarEclipse>(eventType); }},
        {string("PotionsMerchant"), [&]() { return std::make_shared<PotionsMerchant>(eventType); }},
        {string("Snail"), [&]() { return MonsterFactory::createMonster(eventType); }},
        {string("Slime"), [&]() { return MonsterFactory::createMonster(eventType); }},
        {string("Balrog"), [&]() { return MonsterFactory::createMonster(eventType); }},
        //{string("Pack"), [&]() { return MonsterFactory::createMonster(eventType); }},
    };

    auto it = EventMap.find(eventType);
    if (it != EventMap.end()) {
        return it->second();
    }
    throw std::runtime_error("Invalid Events File");
}

