/*
A virtual function is a special type of function that, when called, resolves to the most-derived
version of the function that exists between the base and derived class. This capability is known as polymorphism.

A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const)
and return type as the base version of the function. Such functions are called overrides and are implicitly virtual.

The ability to structure your code in such a way that newly derived classes will automatically work with the
old code without modification is one of the biggest benefits of virtual functions.

The signature of the derived class function must exactly match the signature of the base class virtual function
in order for the derived class function to be used.

It’s generally a good idea to use the virtual keyword for virtualized functions in derived classes
even though it’s not strictly necessary.

The return type of a virtual function and its override must match.

Never call virtual functions from constructors or destructors.

Making virtual functions is generaly inefficient.
*/

#include <iostream>
#include <string>
#include <string_view>

class Animal {
protected:
    std::string m_name;
    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(const std::string& name) : m_name{ name } {}
public:
    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }
};

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal{ name } {}
    virtual std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal{ name } { }
    virtual std::string_view speak() const { return "Woof"; }
};

void report(const Animal& animal) {
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main() {
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };

    report(cat);
    report(dog);

    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };

    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal* animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto* animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';

    for (const auto* animal : animals)
        report(*animal);
}