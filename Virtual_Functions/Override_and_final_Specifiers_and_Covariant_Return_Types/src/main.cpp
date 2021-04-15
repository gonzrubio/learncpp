/*
The override specifier can be applied to any override function by placing the specifier in the same place const would go.
There is no performance penalty for using the override specifier, and it helps avoid inadvertent errors.
Apply the override specifier to every intended override function you write.

There may be cases where you don’t want someone to be able to override a virtual function, or inherit from a class.
The final specifier can be used to tell the compiler to enforce this, the final specifier is used in the same place
the override specifier is. In the case where we want to prevent inheriting from a class, the final specifier is applied
after the class name.

 If the return type of a virtual function is a pointer or a reference to a class, override functions can return a
 pointer or a reference to a derived class. These are called covariant return types.
*/

#include <iostream>

/// Override
class A {
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
	virtual const char* getName3(int x) { return "A"; }
	virtual const char* getName() { return "A"; }
};

class B : public A {
public:
	// virtual const char* getName1(short int x) override { return "B"; } // compile error, function is not an override
	// virtual const char* getName2(int x) const override { return "B"; } // compile error, function is not an override
	virtual const char* getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)
	// note use of final specifier on following line -- that makes this function no longer overridable
	virtual const char* getName() override final { return "B"; } // okay, overrides A::getName()
};


class C : public B {
public:
	// virtual const char* getName() override { return "C"; } // compile error: overrides B::getName(), which is final
};

/// Covariant return types

class Base {
public:
	// This version of getThis() returns a pointer to a Base class
	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base {
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	Derived* getThis() override { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};

int main() {
	Derived d{};
	Base* b{ &d };
	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
	b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType
	return 0;
}