#pragma once


#include "Event.h"
#include <map>
#include <string>


//EventFactory
class EventFactory {
    //std::map<std::string, std::unique_ptr<Event>()> eventsMap;
public:
    static std::unique_ptr<Event> createEvent(const std::string &eventType);
};
