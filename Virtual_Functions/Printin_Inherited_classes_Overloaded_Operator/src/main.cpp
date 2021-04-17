/*
Only member functions can be virtualized -- this makes sense, since only classes can inherit from other
classes, and there’s no way to override a function that lives outside of a class (you can overload
non-member functions, but not override them). Because we typically implement operator<< as a friend,
and friends aren’t considered member functions, a friend version of operator<< is ineligible to be virtualized.

 Even if we could virtualize operator<< there’s the problem that the function parameters for Base::operator<< and
 Derived::operator<< differ (the Base version would take a Base parameter and the Derived version would take
 a Derived parameter). Consequently, the Derived version wouldn’t be considered an override of the Base version,
 and thus be ineligible for virtual function resolution.

 The solution: First, we set up operator<< as a friend in our base class as usual. But instead of having
 operator<< do the printing itself, we delegate that responsibility to a normal member function that can be virtualized.
*/

#include <iostream>

class Base {
public:
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Base& b) {
		// Delegate printing responsibility for printing to member function print()
		return b.print(out);
	}

	// We'll rely on member function print() to do the actual printing
	// Because print is a normal member function, it can be virtualized.
	virtual std::ostream& print(std::ostream& out) const {
		out << "Base";
		return out;
	}
};

class Derived : public Base {
public:
	// Here's our override print function to handle the Derived case
	virtual std::ostream& print(std::ostream& out) const override {
		out << "Derived";
		return out;
	}
};

int main() {
	Base b{};
	std::cout << b << '\n';

	Derived d{};
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

	Base& bref{ d };
	std::cout << bref << '\n';
}