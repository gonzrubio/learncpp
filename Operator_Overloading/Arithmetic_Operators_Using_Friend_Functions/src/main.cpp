/*
All arithmetic operators are binary operators and they are all overloaded
in the same way. There are three ways to overload operators: the memeber
function way, the friend function way, and te normal function way.
*/

#include <iostream>

class Cents {
private:
    int m_cents;
public:
    Cents(int cents) { m_cents = cents; }
    int get_cents() const { return m_cents; }
    friend Cents operator+(const Cents& c1, const Cents& c2);
    friend Cents operator-(const Cents& c1, const Cents& c2);
    friend Cents operator*(const Cents& c1, const Cents& c2);
    friend Cents operator/(const Cents& c1, const Cents& c2);
};

Cents operator+(const Cents &c1, const Cents &c2) {
    return Cents(c1.m_cents + c2.m_cents);
}

Cents operator-(const Cents &c1, const Cents &c2) {
    return Cents(c1.m_cents - c2.m_cents);
}

Cents operator*(const Cents &c1, const Cents &c2) {
    return Cents(c1.m_cents * c2.m_cents);
}

Cents operator/(const Cents &c1, const Cents &c2) {
    return Cents(c1.m_cents / c2.m_cents);
}

void cents() {
    Cents cents1{ 2 };
    Cents cents2{ 2 };
    std::cout << Cents(cents1 + cents2).get_cents() << std::endl;
    std::cout << Cents(cents1 * cents2).get_cents() << std::endl;
    std::cout << Cents(cents1 / cents2).get_cents() << std::endl;
}

class MinMax {
public:
    MinMax(int min, int max) {
        m_min = min;
        m_max = max;
    }
    int get_min() const { return m_min; }
    int get_max() const { return m_max; }
    friend MinMax operator+(const MinMax& m1, const MinMax& m2);

private:
    int m_min;
    int m_max;

};

MinMax operator+(const MinMax& m1, const MinMax& m2) {
    // Keep track of the minimum and maximum values seen so far.
    int min{ m1.m_min < m2.m_min ? m1.m_min : m2.m_min };
    int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };
    return MinMax(min, max);
}

void min_max() {
    MinMax m1{ 10, 15 };
    MinMax m2{ 8, 11 };
    MinMax m3{ 3, 12 };
    MinMax m_final{ m1 + m2 + m3 };
    std::cout << m_final.get_min() << " " << m_final.get_max() << std::endl;
}

class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator=0, int denominator=1): m_numerator{ numerator }, m_denominator{ denominator } {
        // We put reduce() in the constructor to ensure any fractions we make get reduced!
        // Since all of the overloaded operators create new Fractions, we can guarantee this will get called here        
        reduce();
    }
    // We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
    static int gcd(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce()
    {
        if (m_numerator != 0 && m_denominator != 0)
        {
            int gcd{ Fraction::gcd(m_numerator, m_denominator) };
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }
    void print() const {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int constant);
    friend Fraction operator*(int constant, const Fraction& f1);

};

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator );
}

Fraction operator*(const Fraction& f1, int constant) {
    return Fraction(f1.m_numerator * constant, f1.m_denominator);
}

Fraction operator*(int constant, const Fraction& f1) {
    return operator*(f1, constant);
}

void Q1() {
    //Fraction f1{ 1, 4 };
    //f1.print();

    //Fraction f2{ 1, 2 };
    //f2.print();

    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{ 0, 6 };
    f7.print();
}

int main(){
    cents();
    min_max();
    Q1();
}