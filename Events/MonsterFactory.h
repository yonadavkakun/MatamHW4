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
    using MonsterCreator = std::function<std::unique_ptr<Monster>()>;
    /**
     * creates a unique_ptr to a monster in eventStream
     * throws an exception if a monster is invalid
     *
     * @param eventsStream
     * @return unique_ptr<Monster> monster
     */
    static std::unique_ptr<Monster> createMonster(std::istream &eventsStream);
};
