/*
When dealing with polymorphism, you’ll often encounter cases where you have a pointer to a base class,
but you want to access some information that exists only in a derived class.

C++ will implicitly let you convert a Derived pointer into a Base pointer. This process is sometimes called upcasting.
Dynamic casts have a few different capabilities, by far the most common use for dynamic casting is for converting
base-class pointers into derived-class pointers. This process is called downcasting.

If a dynamic_cast fails, the result of the conversion will be a null pointer. In order to programs safe,
we need to ensure the result of the dynamic_cast actually succeeded.
Because dynamic_cast does some consistency checking at runtime (to ensure the conversion can be made),
use of dynamic_cast does incur a performance penalty.

Static_cast does no runtime type checking to ensure that what you’re doing makes sense.
This makes using static_cast faster, but more dangerous. Dynamic_cast can’t return a null reference upon failure.
Instead, if the dynamic_cast of a reference fails, an exception of type std::bad_cast is thrown.

In general, using a virtual function should be preferred over downcasting.
However, there are times when downcasting is the better choice:
	- When you can not modify the base class to add a virtual function (e.g. because the base class is part of
	the standard library).
	- When you need access to something that is derived-class specific (e.g. an access function that only exists
	in the derived class).
	- When adding a virtual function to your base class doesn’t make sense (e.g. there is no appropriate value
	for the base class to return). Using a pure virtual function may be an option here if you don’t need to
	instantiate the base class.
*/

#include <iostream>
#include <string>

class Base {
protected:
	int m_value{};
public:
	Base(int value) : m_value{ value } {}
	virtual ~Base() = default;
};

class Derived : public Base {
protected:
	std::string m_name{};
public:
	Derived(int value, const std::string& name) : Base{ value }, m_name{ name } {}
	const std::string& getName() const { return m_name; }
};

Base* getObject(bool bReturnDerived) {
	if (bReturnDerived)
		return new Derived{ 1, "Apple" };
	else
		return new Base{ 2 };
}

int main() {
	Base* base{ getObject(true) };

	// Use dynamic cast to convert Base pointer into Derived pointer.
	Derived* derived{ dynamic_cast<Derived*>(base) };
	if (derived)
		std::cout << derived->getName() << std::endl;
	else
		std::cout << "Base" << std::endl;

	Derived apple{ 1, "Apple" };
	Base& rapple{ apple }; // Set Base reference to Derived pbject.
	std::cout << dynamic_cast<Derived&>(rapple).getName() << std::endl;

	delete base;
}


