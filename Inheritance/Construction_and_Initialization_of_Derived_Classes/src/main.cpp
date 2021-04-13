/*
Here’s what actually happens when base is instantiated:
	- Memory for base is set aside
	- The appropriate Base constructor is called
	- The initialization list initializes variables
	- The body of the constructor executes
	- Control is returned to the caller

Here’s what actually happens when derived is instantiated:
	- Memory for derived is set aside (enough for both the Base and Derived portions)
	- The appropriate Derived constructor is called
	- The Base object is constructed first using the appropriate Base constructor.
		If no base constructor is specified, the default constructor will be used.
	- The initialization list initializes variables
	- The body of the constructor executes
	- Control is returned to the caller

The value of a member variable can only be set in an initialization list of a constructor
belonging to the same class as the variable. Only non-inherited variables can be initialized
in the initialization list. Inherited variables can still have their values changed in the
body of the constructor using an assignment.

Recall that const values and references have to be initialized in the initialization list of the constructor.
Add the constructor of the base class in the memebr initialization list of the derived class.

Constructors can only call constructors from their immediate parent/base class.
*/

#include <iostream>
#include <string>
class Base {
private:
	int m_id;

public:
	Base(int id = 0) : m_id{ id } {
	}
	int getId() const { return m_id; }
};

class Derived : public Base {
private:
	double m_cost;
public:
	Derived(double cost = 0.0, int id = 0)
		: Base{ id }, // Call Base(int) constructor with value id!
		m_cost{ cost }
	{
	}
	double getCost() const { return m_cost; }
};

class Fruit {
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(const std::string& name = "", const std::string& color = "") :
		m_name{ name }, m_color{ color } {

	}
	const std::string& get_name() const { return m_name; }
	const std::string& get_color() const { return m_color; }
};

class Apple : public Fruit {
private:
	double m_fiber;
public:
	Apple(const std::string& name = "", const std::string& color = "", const double fiber = 0.0) :
		m_fiber{ fiber }, Fruit{ name, color } {

	}
	friend std::ostream& operator<<(std::ostream& out, const Apple& apple) {
		out << "Apple (" << apple.get_name() << ", " << apple.get_color() << ", " << apple.m_fiber << ")";
		return out;
	}
};

class Banana : public Fruit {
public:
	Banana(const std::string& name = "", const std::string& color = "") :
		Fruit{ name, color } {

	}
	friend std::ostream& operator<<(std::ostream& out, const Banana& banana) {
		out << "Banana (" << banana.get_name() << ", " << banana.get_color() << ")";
		return out;
	}
};

int main() {

	Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
	std::cout << "Id: " << derived.getId() << '\n';
	std::cout << "Cost: " << derived.getCost() << '\n';

	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';
}