
#include "MatamStory.h"
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <memory>
#include <memory>
#include "Utilities.h"
#include "Events/EventFactory.h"


MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream) {
    while (!eventsStream.eof()) {
        events.push_back(EventFactory::createEvent(eventsStream));
    }
    if (events.size() < 2) {
        throw std::runtime_error("Invalid Events File");
    }
    /*============================================*/
    while (!playersStream.eof()) {
        players.push_back(PlayerFactory::createPlayer(playersStream));
    }
    if (players.size() < 2 || players.size() > 6) {
        throw std::runtime_error("Invalid Players File");
    }
    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player &player) {
    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */
    currEvent = events[(m_turnIndex - 1) % events.size()];
    printTurnDetails(m_turnIndex, player, currEvent.operator*());
    printTurnOutcome(currEvent.operator*().applyEvent(player));
    m_turnIndex++;
}

void MatamStory::playRound() {
    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for (std::vector<std::shared_ptr<Player> >::iterator it = players.begin(); it != players.end(); ++it) {
        if (it.operator*()->getHealthPoints() != 0) {
            playTurn(**it);
        }
    }
    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    std::vector<std::shared_ptr<Player> > sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(),
              [](const std::shared_ptr<Player> &a, const std::shared_ptr<Player> &b) {
                  return *a < *b;
              });
    unsigned int counter = 1;
    for (std::vector<std::shared_ptr<Player> >::iterator it = sortedPlayers.begin(); it != sortedPlayers.end(); ++it) {
        printLeaderBoardEntry(counter, **it);
        counter++;
    }
    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    bool hasLevel10Player = std::any_of(players.begin(), players.end(),
                                        [](const std::shared_ptr<Player> &player) {
                                            return player->getLevel() == 10;
                                        });

    bool allPlayersHealthZero = std::all_of(players.begin(), players.end(),
                                            [](const std::shared_ptr<Player> &player) {
                                                return player->getHealthPoints() == 0;
                                            });
    if (hasLevel10Player) {
        std::vector<std::shared_ptr<Player> > sortedPlayers = players;
            std::sort(sortedPlayers.begin(), sortedPlayers.end(),
                      [](const std::shared_ptr<Player> &a, const std::shared_ptr<Player> &b) {
                          return *a < *b;
                      });
        printGameOver();
        printWinner(*sortedPlayers.at(0));
        return true;
    } else if (allPlayersHealthZero) {
        printGameOver();
        printNoWinners();
        return true;
    } else {
        return false;
    }
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/
    unsigned int counter = 1;
    for (std::vector<std::shared_ptr<Player> >::iterator it = players.begin(); it != players.end(); ++it) {
        printStartPlayerEntry(counter, **it);
        counter++;
    }
    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}
