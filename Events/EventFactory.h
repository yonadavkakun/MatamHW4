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

    static std::shared_ptr<Event> createEvent(const std::string &eventType);
};
