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

    static std::shared_ptr<Monster> createMonster(std::istream &eventsStream);
};
