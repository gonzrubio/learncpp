/*
What happens if instead of setting a Base reference or pointer to a Derived object, we simply assign a Derived
object to a Base object? Remember that derived has a Base part and a Derived part. When we assign a Derived
object to a Base object, only the Base portion of the Derived object is copied. The Derived portion is not
That Derived portion has effectively been “sliced off”. Consequently, the assigning of a Derived class object
to a Base class object is called object slicing (or slicing for short).

Slicing is much more likely to occur accidentally with functions. Slicing here can all be easily avoided by
making the function parameter a reference instead of a pass by value (yet another reason why passing classe
by reference instead of value is a good idea).

Yet another area where new programmers run into trouble with slicing is trying to implement polymorphism with std::vector.
One way to address this is to make a vector of pointers.

You should generally try to avoid slicing. Make sure your function parameters are references (or pointers) and
try to avoid any kind of pass-by-value when it comes to derived classes.
*/

#include <iostream>
#include <vector>

class Base {
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived : public Base {
public:
    Derived(int value)
        : Base{ value }
    {
    }

    virtual const char* getName() const { return "Derived"; }
};

void printName(const Base base) { // note: base passed by value, not reference
    std::cout << "I am a " << base.getName() << '\n';
}

void printName(const Base& base) { // note: base now passed by reference
    std::cout << "I am a " << base.getName() << '\n';
}
int main() {
    std::vector<Base*> v{};

    Base b{ 5 }; // b and d can't be anonymous objects
    Derived d{ 6 };

    v.push_back(&b); // add a Base object to our vector
    v.push_back(&d); // add a Derived object to our vector

    // Print out all of the elements in our vector
    for (const auto* element : v)
        std::cout << "I am a " << element->getName() << " with value " << element->getValue() << '\n';
}