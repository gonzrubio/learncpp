#include "Monster.h"
#include <iostream>

Monster::Monster(Type type, const std::string& name, const std::string& roar, int hits)
	: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hit_points{ hits } {
}

// We're returning strings that are known at compile-time.
// Returning std::string could add a considerable run-time cost.
std::string_view Monster::getTypeString() const {
    switch (m_type)
    {
    case Type::dragon: return "dragon";
    case Type::goblin: return "goblin";
    case Type::ogre: return "ogre";
    case Type::orc: return "orc";
    case Type::skeleton: return "skeleton";
    case Type::troll: return "troll";
    case Type::vampire: return "vampire";
    case Type::zombie: return "zombie";
    default: return "???";
    }
}

void Monster::print() const {
    std::cout << m_name << " the " << getTypeString() << " has " << m_hit_points
        << " hit points and says " << m_roar << '\n';
}
