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

    /**
     * creates a shared_ptr to an event in eventStream
     * throws an exception if an event is invalid
     *
     * @param eventsStream
     * @return shared_ptr<Event> event
     */
    static std::shared_ptr<Event> createEvent(std::istream &eventsStream);
};
