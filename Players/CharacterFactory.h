#pragma once
#include <map>
#include <memory>
#include <functional>
#include "Character.h"

class CharacterFactory {
public:
    using CharacterCreator = std::function<std::shared_ptr<Character>()>;

    static std::shared_ptr<Character> createCharacter(const std::string &charType);
};
