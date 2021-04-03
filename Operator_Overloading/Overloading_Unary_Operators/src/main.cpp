/*
Unary operators operatre on a single operand. Because they only operate on the operand that they are being applied to,
they are typically implemented as member functions. Meaning the member function takes no parameters and acts on the
*this object. 
*/

#include <iostream>

class Cents {
private:
    int m_cents;
public:
    Cents(int cents) { m_cents = cents; }
    int get_cents() { return m_cents; }
    Cents operator-() const;
};

Cents Cents::operator-() const {
    return Cents(-m_cents);
}

void negation() {
    const Cents nickle(5);
    std::cout << "A nickle of debt is worth " << (-nickle).get_cents() << " cents\n";
}

class Point {
private:
    double m_x, m_y, m_z;
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{ x }, m_y{ y }, m_z{ z } {}
    double get_x() const { return m_x; }
    double get_y() const { return m_y; }
    double get_z() const { return m_z; }
    Point operator-() const;  // Convert a Point into its negative equivalent 
    Point operator+() const;  // Convert a Point into its positive equivalent 
    bool operator!() const;   // Return true if the point is set at the origin
};

Point Point::operator-() const {
    return Point(-m_x, -m_y, -m_z);
}

bool Point::operator!() const {
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0 );
}

void negation_and_logical_negation() {
    Point point{}; // use default constructor to set to (0.0, 0.0, 0.0)

    if (!point)
        std::cout << "point is set at the origin.\n";
    else
        std::cout << "point is not set at the origin.\n";
}

Point Point::operator+() const {
    return Point(m_x, m_y, m_z);
}

void quiz() {
    // Implement overloaded operator+ for the Point class.
    Point point{ -1.0, -1.0, -1.0 };
    Point point2{ +point };
    std::cout << point2.get_x();
}

int main() {
    negation();
    negation_and_logical_negation();
    quiz();
}