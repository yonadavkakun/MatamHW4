#include "PlayersJobs.h"

#include <utility>

//warrior

Warrior::Warrior(const std::string &playerName, std::shared_ptr<Character> playerCharacter)
    : Player(playerName, std::move(playerCharacter)) {
    currHealthPoints += 50;
    maxHealthPoints += 50;
}

string Warrior::getJob() const {
    return "Warrior";
}

int Warrior::getCombatPower() const {
    return 2 * force + level;
}

//archer

Archer::Archer(const std::string &playerName, std::shared_ptr<Character> playerCharacter)
    : Player(playerName, std::move(playerCharacter)) {
    coins += 10;
}

string Archer::getJob() const {
    return "Archer";
}

//magician

Magician::Magician(const std::string &playerName, std::shared_ptr<Character> playerCharacter)
    : Player(playerName, std::move(playerCharacter)) {
}

string Magician::getJob() const {
    return "Magician";
}

void Magician::solarEclipseEffect() {
    force++;
}

