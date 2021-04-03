/*
There are two versions of the increment and decrement operators: a prefix increment and decrement (e.g. ++x; --y;) and a
postfix increment and decrement (e.g. x++; y--;). Because the increment and decrement operators are both unary operators
and they modify their operands, they’re best overloaded as member functions.

C++ uses a “dummy variable” or “dummy argument” for the postfix operators. This argument is a fake integer parameter that
only serves to distinguish the postfix version of increment/decrement from the prefix version.

Because the dummy parameter is not used in the function implementation, we have not even given it a name. This tells the
compiler to treat this variable as a placeholder, which means it won’t warn us that we declared a variable but never used it.
*/

#include <iostream>

class Digit
{
private:
    int m_digit;
public:
    Digit(int digit = 0) : m_digit(digit) {}
    Digit& operator++();   // prefix
    Digit& operator--();   // prefix
    Digit operator++(int); // postfix
    Digit operator--(int); // postfix
    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

Digit& Digit::operator++() {
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;
    return *this;
}

Digit& Digit::operator--() {
    // If our number is already at 0, wrap around to 9
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;
    return *this;
}

Digit Digit::operator++(int) {
    // Create a temporary variable with our current digit
    Digit temp(m_digit);

    // Use prefix operator to increment this digit
    ++(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

Digit Digit::operator--(int) {
    // Create a temporary variable with our current digit
    Digit temp(m_digit);

    // Use prefix operator to decrement this digit
    --(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}


std::ostream& operator<< (std::ostream& out, const Digit& d) {
    out << d.m_digit;
    return out;
}

int main() {
    Digit digit(8);

    std::cout << digit << std::endl;
    std::cout << ++digit << std::endl;
    std::cout << ++digit << std::endl;
    std::cout << --digit << std::endl;
    std::cout << --digit << std::endl;
    std::cout << digit++ << std::endl;
    std::cout << digit-- << std::endl;

    return 0;
}
