#pragma once


#include "Events/Event.h"
#include "Players/Player.h"
#include <map>
#include <string>


//EventFactory
class EventFactory {
    //std::map<std::string, std::unique_ptr<Event>()> eventsMap;
public:
    static std::unique_ptr<Event> createEvent(const std::string &eventType);
};

template<class T>
std::unique_ptr<Event> buildEvent();


//PlayerFactory
class PlayerFactory {
    //std::map<std::string, std::unique_ptr<Player>()> playersMap;
public:
    static std::unique_ptr<Player> createPlayer(const std::string &playerType);
};

template<class T>
std::unique_ptr<Player> buildPlayer();
