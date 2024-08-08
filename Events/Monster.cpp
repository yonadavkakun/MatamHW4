# include "Monster.h"

string Monster::getDescription() const {
    string result = name + "(power " + std::to_string(combatPower) + ", "
                    + "loot " + std::to_string(loot)
                    + ", " + "damage " + std::to_string(damage) + ")";
    return result;
}
