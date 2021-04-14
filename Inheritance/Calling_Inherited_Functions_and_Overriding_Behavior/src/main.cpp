/*
When a member function is called with a derived class object, the compiler first looks to see if that
member exists in the derived class. If not, it begins walking up the inheritance chain and checking
whether the member has been defined in any of the parent classes. This means that if the behavior
provided by a base class is sufficient, we can simply use the base class behavior.

To modify the way a function defined in a base class works in the derived class, simply redefine the
function in the derived class. When you redefine a function in the derived class, the derived function
does not inherit the access specifier of the function with the same name in the base class. It uses
whatever access specifier it is defined under in the derived class. Therefore, a function that is
defined as private in the base class can be redefined as public in the derived class, or vice-versa.

It is possible to have our derived function call the base version of the function of the same name
(in order to reuse code) and then add additional functionality to it.
*/

#include <iostream>

class Base
{
private:
	int m_value{};

public:
	Base(int value)
		: m_value{ value }
	{
	}

	friend std::ostream& operator<< (std::ostream& out, const Base& b)
	{
		out << "In Base\n";
		out << b.m_value << '\n';
		return out;
	}
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	friend std::ostream& operator<< (std::ostream& out, const Derived& d)
	{
		out << "In Derived\n";
		// static_cast Derived to a Base object, so we call the right version of operator<<
		out << static_cast<const Base&>(d);
		return out;
	}
};


int main() {
	Derived derived{ 7 };

	std::cout << derived << '\n';

	return 0;
}