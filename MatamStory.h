
#pragma once

#include <iostream>

#include "Players/Player.h"
#include "Events/Event.h"
#include "Players/Character.h"
#include "Players/PlayersJobs.h"
#include "Events/Monster.h"
#include "Utilities.h"
#include "Events/EventFactory.h"
#include "Players/PlayerFactory.h"

class MatamStory {
private:
 unsigned int m_turnIndex;
 std::vector<std::shared_ptr<Event> > events;
 std::vector<std::shared_ptr<Player> > players;
 std::shared_ptr<Event> currEvent;
 std::shared_ptr<Player> currPlayer;
 /**
  * Playes a single turn for a player
  *
  * @param player - the player to play the turn for
  *
  * @return - void
 */
 void playTurn(Player &player);

 /**
  * Plays a single round of the game
  *
  * @return - void
 */
 void playRound();

 /**
  * Checks if the game is over
  *
  * @return - true if the game is over, false otherwise
 */
 bool isGameOver() const;

public:
 /**
  * Constructor of MatamStory class
  *
  * @param eventsStream - events input stream (file)
  * @param playersStream - players input stream (file)
  *
  * @return - MatamStory object with the given events and players
  *
 */
 MatamStory(std::istream &eventsStream, std::istream &playersStream);

 /**
  * Plays the entire game
  *
  * @return - void
 */
 void play();
};
