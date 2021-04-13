/*
First, the most-base class (at the top of the inheritance tree) is constructed first.
Then each child class is constructed in order, until the most-child class (at the bottom
of the inheritance tree) is constructed last.

logically, a child can not exist without a parent. It’s also the safe way to do things:
the child class often uses variables and functions from the parent, but the parent class
knows nothing about the child. Instantiating the parent class first ensures those variables
are already initialized by the time the derived class is created and ready to use them.
*/

#include <iostream>

class Base
{
public:
    int m_id;

    Base(int id = 0)
        : m_id(id)
    {
        std::cout << "Base\n";
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
public:
    double m_cost;

    Derived(double cost = 0.0)
        : m_cost(cost)
    {
        std::cout << "Derived\n";
    }

    double getCost() const { return m_cost; }
};

int main() {
    std::cout << "Instantiating Base\n";
    Base cBase;

    std::cout << "Instantiating Derived\n";
    Derived cDerived;

    return 0;
}