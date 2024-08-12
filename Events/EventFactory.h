#pragma once
#include <map>
#include <memory>
#include <functional>
#include <stdexcept>
#include <string>
#include "Event.h"
#include "MonsterFactory.h"
using std::string;


class EventFactory {
public:
    using EventCreator = std::function<std::shared_ptr<Event>()>;

    static std::shared_ptr<Event> createEvent(const std::string &eventType) {
        const static std::map<std::string, EventCreator> EventMap = {
            {string("SolarEclipse"), [&]() { return std::make_shared<SolarEclipse>(eventType); }},
            {string("PotionsMerchant"), [&]() { return std::make_shared<PotionsMerchant>(eventType); }},
            {string("Snail"), [&]() { return MonsterFactory::createMonster(eventType); }},
            {string("Slime"), [&]() { return MonsterFactory::createMonster(eventType); }},
            {string("Balrog"), [&]() { return MonsterFactory::createMonster(eventType); }},
        };

        auto it = EventMap.find(eventType);
        if (it != EventMap.end()) {
            return it->second();
        }
        throw std::runtime_error("Invalid Event type");
    }
};
