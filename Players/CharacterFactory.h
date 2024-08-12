#pragma once
#include <map>
#include <memory>
#include <functional>
#include "Character.h"

class CharacterFactory {
public:
    using CharacterCreator = std::function<std::shared_ptr<Character>()>;

    static std::shared_ptr<Character> createCharacter(const std::string &charType) {
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
};
