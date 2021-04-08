/*
The default copy constructor and default assignment operators it provides use a copying
method known as a memberwise copy (also known as a shallow copy). This means that C++ copies
each member of the class individually (using the assignment operator for overloaded operator=,
and direct initialization for the copy constructor). When classes are simple (e.g. do not
contain any dynamically allocated memory), this works very well.

When designing classes that handle dynamically allocated memory, memberwise (shallow)
copying can get us in a lot of trouble! This is because shallow copies of a pointer just
copy the address of the pointer -- it does not allocate any memory or copy the contents
being pointed to!

The root of this problem is the shallow copy done by the copy constructor -- doing a
shallow copy on pointer values in a copy constructor or overloaded assignment operator is
almost always asking for trouble

One answer to this problem is to do a deep copy on any non-null pointers being copied.
A deep copy allocates memory for the copy and then copies the actual value, so that the copy
lives in distinct memory from the source. This way, the copy and source are distinct and
will not affect each other in any way. Doing deep copies requires that we write our own
copy constructors and overloaded assignment operators.

Summary
    - The default copy constructor and default assignment operators do shallow copies,
    which is fine for classes that contain no dynamically allocated variables.
    - Classes with dynamically allocated variables need to have a copy constructor and
    assignment operator that do a deep copy.
    - Favor using classes in the standard library over doing your own memory management.
*/

#include <cassert>
#include <cstring>
#include <iostream>

class Fraction {
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator } {
        assert(denominator != 0);
    }

    // Copy constructor
    Fraction(const Fraction& f) :
        m_numerator{ f.m_numerator }, m_denominator{ f.m_denominator } {}

    Fraction& operator= (const Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

Fraction& Fraction::operator= (const Fraction& fraction) {
    // self-assignment guard
    if (this == &fraction)
        return *this;

    // do the copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    return *this; // return the existing object so we can chain this operator
}

class MyString {
private:
    char* m_data{};
    int m_length{};

public:
    MyString(const char* source = "") {
        assert(source); // make sure source isn't a null string

        // Find the length of the string plus one character for a terminator.
        m_length = std::strlen(source) + 1;

        m_data = new char[m_length]; // Allocate a buffer equal to this length.

        // Copy the parameter string into our internal buffer
        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source[i];

        m_data[m_length - 1] = '\0'; // Make sure the string is terminated
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }
    void deep_copy(const MyString& source);
    MyString(const MyString& source) { deep_copy(source); }
    MyString& operator=(const MyString& source);

    ~MyString() {
        // Destructor. We need to deallocate our string
        delete[] m_data;
    }
};

void MyString::deep_copy(const MyString& source) {
    // First, we need to de-allocate any value that this string is holding.
    delete[] m_data;

    // Because m_length is not a pointer, we cahn shallow copy it.
    m_length = source.m_length;

    // m_data is a pointer so we need to deeo copy it if is not null.
    if (source.m_data) {
        // Allocate memeory for our copy.
        m_data = new char[m_length];

        // do the copy.
        for (int i{ 0 }; i < m_length; i++)
            m_data[i] = source.m_data[i];
    } else {
        m_data = nullptr;
    }
}

MyString& MyString::operator=(const MyString& source) {
    // check for self-assignment
    if (this != &source) {
        // now do the deep copy
        deep_copy(source);
    }
    return *this;
}

int main() {

}