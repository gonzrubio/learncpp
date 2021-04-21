/*
Occasionally you may run into a case where you want to catch an exception, but not want
to (or have the ability to) fully handle it at the point where you catch it.

One solution is to throw a new exception. Only exceptions thrown within a try block are
eligible to be caught. This means that an exception thrown within a catch block will not
be caught by the catch block it’s in. Instead, it will be propagated up the stack to the caller.

The exception thrown from the catch block can be an exception of any type -- it doesn’t
need to be the same type as the exception that was just caught.

C++ provides a way to rethrow the exact same exception as the one that was just caught.
To do so, simply use the throw keyword from within the catch block (with no associated variable).

*/

#include <iostream>

class Base {
public:
    Base() {}
    virtual void print() { std::cout << "Base"; }
};

class Derived : public Base {
public:
    Derived() {}
    virtual void print() { std::cout << "Derived"; }
};

int main() {
    try {
        try {
            throw Derived{};
        }
        catch (Base& b) {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            std::cout << "\n";
            throw; // note: We're now rethrowing the object here
        }
    }
    catch (Base& b) {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << "\n";
    }
    return 0;
}