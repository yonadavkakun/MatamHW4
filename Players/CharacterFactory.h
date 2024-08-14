#pragma once
#include <map>
#include <memory>
#include <functional>
#include "Character.h"

class CharacterFactory {
public:
    using CharacterCreator = std::function<std::shared_ptr<Character>()>;
    /**
     * creates a shared_ptr to a character in accordance with charType
     * throws an exception if a character is invalid
     *
     * @param charType
     * @return shared_ptr<Character> character
     */
    static std::shared_ptr<Character> createCharacter(const std::string &charType);
};
