#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {
public:
    enum Type {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types // so we can count how many enumerators are there.
    };
private:
    Type m_type;
    std::string m_name;
    std::string m_roar;
    int m_hit_points;
public:
    Monster(Type type, const std::string& name, const std::string& roar, int hits);
    std::string_view getTypeString() const;
    void print() const;
};

#endif // !MONSTER_H

