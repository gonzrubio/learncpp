/*
Avoid using copy initialization, and use uniform initialization instead. Copy initialization
for classes could potentially make a call to the the constructor and another to the copyu constructor.

Copy initialization also happens you pass or return a class by value. Since C++17 the compiler can elide
the copy constructor even the variable is returned by value.
*/

#include <iostream>
#include <cassert>

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator) {
        assert(denominator != 0);
    }

    // Copy constructor.
    Fraction(const Fraction& copy) :
        m_numerator{ copy.m_numerator }, m_denominator{ copy.m_denominator } {
        // no need to check for a denominator of 0 here since copy must already be a valid Fraction
        std::cout << "Copy constructor called\n";  // just to prove it works
    }

    int get_numerator() const { return m_numerator; }
    void set_numerator(int numerator) { m_numerator = numerator; }
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

Fraction make_negative(const Fraction& f) {
    return Fraction(-f.get_numerator());
}

void fraction() {
    Fraction six = Fraction(6); // Evaluate in the same way as Fraction six = Fraction(6);
    std::cout << six << std::endl;;
    std::cout << make_negative(six) << std::endl;
    Fraction negative_six{ make_negative(six) };
    std::cout << negative_six << std::endl;
}

int main() {
	fraction();
}
