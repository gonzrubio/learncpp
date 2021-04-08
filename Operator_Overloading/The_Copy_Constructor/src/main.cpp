/*
Recall that with direct and unifor initialization, the object being created is directly initialized.
Copy initialization is a little more complicated.

A copy contructor is a special type of constructor used to create a new object as a copy of an existing object.
Like default constructors, C++ will create a public copy constructor if none is provided.

Memberwise initialization means that each member of the copy is initialized directly from the memeber of the
class being copied.

Recall that member access is on a class level meaning, member functions of a class can access the
private members of parameters of the same class type. Since our Fraction copy constructor takes a
parameter of the class type (to make a copy of), we’re able to access the members of parameter
fraction directly, even though it’s not the implicit object.

We can prevent copies of our classes from being made by making the copy constructor private.
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
    Fraction(const Fraction& fraction) :
        m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator) {
        // We can access the members of parameter fraction directly, because we're inside the Fraction class
        // no need to check for a denominator of 0 here since fraction must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

void fraction() {
    Fraction fiveThirds(5, 3);  // Direct initialize a Fraction, calls Fraction(int, int) constructor
    Fraction fCopy(fiveThirds); // Direct initialize -- with Fraction copy constructor
    std::cout << fCopy << '\n';
}

int main() {
    fraction();
}