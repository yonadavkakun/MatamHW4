
#include "MatamStory.h"
#include <vector>
#include <map>
#include <memory>

#include "Utilities.h"

MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream) {
    std::map<string, Event &> eventsMap;
    eventsMap["SolarEclipse"] = SolarEclipse();
    eventsMap["PotionsMerchant"] = PotionsMerchant();
    eventsMap["Snail"] = Snail();
    eventsMap["Slime"] = Slime();
    eventsMap["Balrog"] = Balrog();
    eventsMap["Pack"] = Pack();
    /*===== TODO: Open and read events file =====*/
    std::vector<std::unique_ptr<Event> > events;
    string eventInput;
    while (std::cin >> eventInput) {
        events.push_back(std::unique_ptr<eventsMap[eventInput]>);
    }
    /*==========================================*/

    std::map<string, Event &> playersMap;
    playersMap["Warrior"] = Warrior();
    playersMap["Archer"] = Archer();
    playersMap["Magician"] = Magician();

    /*===== TODO: Open and Read players file =====*/
    std::vector<std::unique_ptr<Event> > players;
    string playerInput;
    while (std::cin >> playerInput) {
        players.push_back(std::unique_ptr<playersMap[playerInput]>);
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
