#include "Creature.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Creature& creature) {
    out << creature.m_name << " is at " << creature.m_location;
    return out;
}

void Creature::move_to(int x, int y) {
    m_location.set_point(x, y);
}
