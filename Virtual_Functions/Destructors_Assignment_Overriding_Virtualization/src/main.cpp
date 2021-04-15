/*
It is sometimes the case that you will want to provide your own destructor (particularly if the class
needs to deallocate memory). You should always make your destructors virtual if you’re dealing with inheritance.
Whenever you are dealing with inheritance, you should make any explicit destructors virtual.

if a base class function is virtual, all derived overrides will be considered virtual regardless of
whether they are specified as such.

If you intend your class to be inherited from, make sure your destructor is virtual.
If you do not intend your class to be inherited from, mark your class as final. This will prevent other
classes from inheriting from it in the first place, without imposing any other use restrictions on the class itself.
*/

#include <iostream>

class Base {
public:
    // note: virtual
    virtual ~Base() {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived : public Base {
private:
    int* m_array;

public:
    Derived(int length) : m_array{ new int[length] } {}
    // note: virtual
    virtual ~Derived()  {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

void virtual_destructor() {
    Derived* derived{ new Derived(5) };
    Base* base{ derived };

    delete base;
}

int main() {
    virtual_destructor();
}
