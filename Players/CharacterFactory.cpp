#include "CharacterFactory.h"

#include <stdexcept>

std::shared_ptr<Character> CharacterFactory::createCharacter(const std::string &charType) {
    const static std::map<std::string, CharacterCreator> characterMap = {
        {"Responsible", [&]() { return std::make_shared<Responsible>(charType); }},
        {"RiskTaking", [&]() { return std::make_shared<RiskTaking>(charType); }}
    };

    auto it = characterMap.find(charType);
    if (it != characterMap.end()) {
        return it->second();
    }
    throw std::runtime_error("Invalid Players File");
}
