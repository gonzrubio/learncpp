#include "Cents.h"

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents &c1, const Cents &c2) {
    // use the Cents constructor and operator+(int, int)
    // we don't need direct access to private members here
    //return { c1.get_cents() + c2.get_cents() };
    return Cents( c1.get_cents() + c2.get_cents() );
}
