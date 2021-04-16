/*
A pure virtual function (or abstract function) has no body at all and simply acts as a placeholder that
is meant to be redefined by derived classes. When we add a pure virtual function to our class, we are
effectively saying, “it is up to the derived classes to implement this function”.

Any class with one or more pure virtual functions becomes an abstract base class, which means that it
can not be instantiated. Any derived class must define a body for this function, or that derived class
will be considered an abstract base class as well.

A pure virtual function is useful when we have a function that we want to put in the base class, but
only the derived classes know what it should return. A pure virtual function makes it so the base class
can not be instantiated, and the derived classes are forced to define these functions before they can
be instantiated. This helps ensure the derived classes do not forget to redefine functions that the
base class was expecting them to.

An interface class is a class that has no member variables, and where all of the functions are pure virtual.
In other words, the class is purely a definition, and has no actual implementation. Interfaces are useful
when you want to define the functionality that derived classes must implement, but leave the details of how
the derived class implements that functionality entirely up to the derived class.
Interface classes are often named beginning with an I.
*/

#include <iostream>
#include <string>

// This is an abstract base class, and acan not be instantiated.
// We are making the memeber variable protected because we do not want the public to acess it
// directly but still want derived classes to be able to access the name of the Animal object.
class Animal {
protected:
	std::string m_name;
public:
	Animal(const std::string& name) : m_name{ name } {}
	const std::string& get_name() const { return m_name; }
	virtual const std::string& speak() const = 0; // Pure virtual function.
	virtual ~Animal() = default;
};

class Cow : public Animal {
public:
	Cow(const std::string& name) : Animal{ name } {}
	virtual const std::string& speak() const override {
		return "Moo";
	}
};

void cow() {
	Cow cow{ "Betsy" };
	std::cout << cow.get_name() << " says: " << cow.speak() << std::endl;
}

class IErrorLog {
public:
	virtual bool openLog(const char* filename) = 0;
	virtual bool closeLog() = 0;
	virtual bool writeError(const char* errorMessage) = 0;
	virtual ~IErrorLog() {} // make a virtual destructor in case we delete an IErrorLog pointer, so the proper derived destructor is called
};

int main() {
	cow();
}