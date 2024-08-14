
#include "MatamStory.h"
#include <vector>
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
    currEvent = events[(m_turnIndex - 1) % events.size()];
    printTurnDetails(m_turnIndex, player, *currEvent);
    printTurnOutcome(currEvent->applyEvent(player));
    m_turnIndex++;
}

void MatamStory::playRound() {
    printRoundStart();

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
    /*========================================================================*/
}
