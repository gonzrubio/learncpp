/*
Overloading the typecast operator helps convert user-defined types.
User-defined conversions do not take parameters, as there is no way to pass arguments to them.
User-defined conversions do not have a return type. C++ assumes you will be returning the correct type.
*/

#include <iostream>

class Cents {
private:
    int m_cents;
public:
    Cents(int cents = 0) : m_cents{ cents } {}
    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
    operator int() { return m_cents; }
};

void print_int(int value) {
    std::cout << value << std::endl;
}

void cents() {
    Cents cents{ 7 };
    print_int(cents.getCents()); // print 7.
    std::cout << static_cast<int>(cents) << std::endl; // print 7.
}

class Dollars {
private:
    int m_dollars;
public:
    Dollars(int dollars = 0) : m_dollars{ dollars } {}

    // Allow us to convert Dollars into Cents
    operator Cents() const { return Cents{ m_dollars * 100 }; }
};

void printCents(Cents cents) {
    std::cout << cents; // cents will be implicitly cast to an int here
}

void dollars() {
    Dollars dollars{ 9 };
    printCents(dollars); // dollars will be implicitly cast to a Cents here
}

int main() {
    cents();
    dollars();
}