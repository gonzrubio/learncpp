/*
When overloading an operator using a member function:
    - The overloaded operator must be added as a member function of the left operand.
    - The left operand becomes the implicit *this object
    - All other operands become function parameters.

Converting a friend overloaded operator to a member overloaded operator is easy:
    1) The overloaded operator is defined as a member instead of a friend (Cents::operator+ instead of friend operator+)
    2) The left parameter is removed, because that parameter now becomes the implicit *this object.
    3) Inside the function body, all references to the left parameter can be removed (e.g. cents.m_cents becomes m_cents,
    which implicitly references the *this object).

Note: The assignment (=), subscript ([]), function call (()), and member selection (->) operators must be overloaded as
member functions, because the language requires them to be. We are not able to overload operator<< as a member function.
Typically, we won’t be able to use a member overload if the left operand is either not a class (e.g. int), or it is a
class that we can’t modify (e.g. std::ostream).
*/

#include <iostream>

class Cents {
private:
    int m_cents;
public:
    Cents(int cents) : m_cents{ cents } {}
    Cents operator+(int value);
    int get_cents() const { return m_cents; }
};

Cents Cents::operator+(int value) {
    return Cents(m_cents + value);
}

int main() {
    Cents cents1{ 6 };
    Cents cents2{ cents1 + 2 };
    std::cout << cents2.get_cents() << std::endl;
}