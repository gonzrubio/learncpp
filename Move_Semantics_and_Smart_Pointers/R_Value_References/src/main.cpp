/*
l-values and r-values are actually not properties of values, but rather, properties of expressions.
Every expression in C++ has two properties: a type (which is used for type checking), and a value
category (which is used for certain kinds of syntax checking, such as whether the result of the
expression can be assigned to).

It’s simplest to think of an l-value (also called a locator value) as a function or an object (or an
expression that evaluates to a function or object). All l-values have assigned memory addresses.
It’s simplest to think of an r-value as “everything that is not an l-value”, they are typically
evaluated for their values, have expression scope (they die at the end of the expression they are in),
and cannot be assigned to.

L-value references can only be initialized with modifiable l-values. L-value references to const objects
can be initialized with l-values and r-values alike. However, those values can’t be modified.
L-value references to const objects are particularly useful because they allow us to pass any type of
argument (l-value or r-value) into a function without making a copy of the argument.

An r-value reference is a reference that is designed to be initialized with an r-value (only).
R-value references have two properties that are useful. First, r-value references extend the lifespan of
the object they are initialized with to the lifespan of the r-value reference (l-value references to
const objects can do this too). Second, non-const r-value references allow you to modify the r-value.

R-value references are more often used as function parameters. This is most useful for function overloads
when you want to have different behavior for l-value and r-value arguments.


Named-objects are l-values. Anonymous objects are r-values. The type of the named object or anonymous
object is independent from whether it’s an l-value or r-value.

You should almost never return an r-value reference, for the same reason you should almost never return
an l-value reference. In most cases, you’ll end up returning a hanging reference when the referenced
object goes out of scope at the end of the function.

*/


#include <iostream>


class Fraction {
private:
	int m_numerator, m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator } {}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};


void example_1() {
	auto&& rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction
	// f1 of operator<< binds to the temporary, no copies are created.
	std::cout << rref << '\n';
} // rref (and the temporary Fraction) goes out of scope here


void fun(const int&) {
	// l-value arguments will select this function
	std::cout << "l-value reference to const\n";
}

void fun(int&&) {
	// r-value arguments will select this function
	std::cout << "r-value reference\n";
}

void example_2() {
	int x{ 5 };
	fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function
}


int main() {
	example_1();
	example_2();
}