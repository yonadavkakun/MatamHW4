#pragma once
#include <map>
#include <memory>
#include <functional>
#include <stdexcept>
#include <string>
#include "Monster.h"
using std::string;


class MonsterFactory {
public:
    using MonsterCreator = std::function<std::shared_ptr<Monster>()>;

    static std::shared_ptr<Monster> createMonster(const std::string &monsterType) {
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
};
