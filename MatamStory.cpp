
#include "MatamStory.h"
#include <vector>
#include <map>
#include <memory>


#include "Events/Event.h"
#include "Events/Monster.h"
#include "Utilities.h"
#include "Events/EventFactory.h"
#include "Players/PlayerFactory.h"


MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream) {
    /*===== TODO: Open and read events file =====*/
    string eventInput;
    while (eventsStream >> eventInput) {
        events.push_back(EventFactory::createEvent(eventInput));
    }
    for (std::vector<std::shared_ptr<Event> >::iterator it = events.begin(); it != events.end(); ++it) {
        std::cout << it.operator*()->getDescription() << std::endl;
    }


    /*==========================================*/
    /*===== TODO: Open and Read players file =====*/
    string playerName;
    while (playersStream >> playerName) {
        string playerJob;
        playersStream >> playerJob;
        string playerCharacter;
        playersStream >> playerCharacter;
        players.push_back(PlayerFactory::createPlayer(playerName, playerJob, playerCharacter));
    }
    /*============================================*/


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

    m_turnIndex++;
}

void MatamStory::playRound() {
    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}
