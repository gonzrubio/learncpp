/*
The assignment operator (operator=) is used to copy values from one object to another already existing object.
The purpose of the copy constructor and the assignment operator are almost equivalent -- both copy one object
to another. However, the copy constructor initializes new objects, whereas the assignment operator replaces
the contents of existing objects.

Summarizing:
	- If a new object has to be created before the copying can occur, the copy constructor is used
	(note: this includes passing or returning objects by value).
	- If a new object does not have to be created before the copying can occur, the assignment operator is used.

The assignment operator must be overloaded as a member function.
The compiler will provide a default public assignment operator for your class if you do not
provide one. This assignment operator does memberwise assignment (which is essentially
the same as the memberwise initialization that default copy constructors do).

Just like other constructors and operators, you can prevent assignments from being made by
making your assignment operator private or using the delete keyword.
*/

#include <cassert>
#include <iostream>

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

    // Copy constructor
    Fraction(const Fraction& copy) :
        m_numerator(copy.m_numerator), m_denominator(copy.m_denominator) {
        // no need to check for a denominator of 0 here since copy must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    Fraction& operator= (const Fraction& fraction);  // Overloaded assignment
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

Fraction& Fraction::operator= (const Fraction& fraction) {
    // self-assignment guard
    if (this == &fraction)
        return *this;

    // do the copy
    m_numerator = fraction.m_numerator;  // can handle self-assignment
    m_denominator = fraction.m_denominator;  // can handle self-assignment

    // return the existing object so we can chain this operator
    return *this;
}

int main() {
    Fraction fiveThirds(5, 3);
    Fraction f;
    f = fiveThirds; // calls overloaded assignment
    std::cout << f << std::endl;

    Fraction f1(5, 3);
    Fraction f2(7, 2);
    Fraction f3(9, 5);

    f1 = f2 = f3; // chained assignment
    std::cout << f1 << std::endl;
    return 0;
}