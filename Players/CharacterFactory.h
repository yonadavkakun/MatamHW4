#pragma once
#include <map>
#include <memory>
#include <functional>
#include "Character.h"

class CharacterFactory {
public:
    using CharacterCreator = std::function<std::unique_ptr<Character>()>;
    /**
     * creates a unique_ptr to a character in accordance with charType
     * throws an exception if a character is invalid
     *
     * @param charType
     * @return unique_ptr<Character> character
     */
    static std::unique_ptr<Character> createCharacter(const std::string &charType);
};
