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
    /**
     * creates a shared_ptr to a monster in eventStream
     * throws an exception if a monster is invalid
     *
     * @param eventsStream
     * @return shared_ptr<Monster> monster
     */
    static std::shared_ptr<Monster> createMonster(std::istream &eventsStream);
};
