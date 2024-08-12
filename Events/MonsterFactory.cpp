#include "MonsterFactory.h"

std::shared_ptr<Monster> MonsterFactory::createMonster(const std::string &monsterType) {
    const static std::map<std::string, MonsterCreator> MonsterMap = {
        {string("Snail"), [&]() { return std::make_shared<Snail>(); }},
        {string("Slime"), [&]() { return std::make_shared<Slime>(); }},
        {string("Balrog"), [&]() { return std::make_shared<Balrog>(); }},
        //{string("Pack"), [&]() { return std::make_shared<Pack>(size); }},
    };

    auto it = MonsterMap.find(monsterType);
    if (it != MonsterMap.end()) {
        return it->second();
    }
    throw std::runtime_error("Invalid Monster type");
}
