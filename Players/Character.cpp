#include "Character.h"

#include <string>

Character::Character(const std::string &characterType): character(characterType) {
}

std::string Character::getCharacter() {
    return character;
}

Responsible::Responsible(const std::string &characterType) : Character(characterType) {
}

RiskTaking::RiskTaking(const std::string &characterType) : Character(characterType) {
}

