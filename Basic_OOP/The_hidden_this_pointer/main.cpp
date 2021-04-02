// The hidden "this" pointer:
// The “this” pointer is a hidden parameter implicitly added to any non-static member function.
// Most of the time, you will not need to access it directly, but you can if needed.
// It’s worth noting that “this” is a const pointer -- you can change the value of the underlying object it points to,
// but you can not make it point to something else!

#include <iostream>

class Calc
{
private:
    int m_value;

public:
    Calc() { m_value = 0; }

    void add(int value) { m_value += value; }
    void sub(int value) { m_value -= value; }
    void mult(int value) { m_value *= value; }

    int getValue() { return m_value; }
};

class CalcChaining
{
private:
    int m_value;

public:
    CalcChaining() { m_value = 0; }

    CalcChaining& add(int value) { m_value += value; return *this; }
    CalcChaining& sub(int value) { m_value -= value; return *this; }
    CalcChaining& mult(int value) { m_value *= value; return *this; }

    int getValue() { return m_value; }
};

void calc_ex() {
    Calc calc;
    calc.add(5); // returns void
    calc.sub(3); // returns void
    calc.mult(4); // returns void

    std::cout << calc.getValue() << '\n';

    CalcChaining calc_chaining;
    calc_chaining.add(5).sub(3).mult(4);

    std::cout << calc_chaining.getValue() << '\n';
}

int main()
{
    calc_ex();
    return 0;
}
