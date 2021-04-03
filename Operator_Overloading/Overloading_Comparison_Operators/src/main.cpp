/*
Comparison operators are binary operators that do not modify the left operand, making friend functions good candidates
for their implementation. 

Tip: Don't define overloaded operators that do not make sense for your class.
*/

#include <iostream>

class Car {
private:
	std::string m_make;
	std::string m_model;
public:
	Car(const std::string& make, const std::string& model) : m_make{ make }, m_model{ model } {}
	friend bool operator== (const Car& c1, const Car& c2);
	friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2) {
	return (c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2) {
	return !(c1 == c2);
}

void equal_not_equal() {
	Car corolla{ "Toyota", "Corolla" };
	Car camry{ "Toyota", "Camry" };

	if (corolla == camry)
		std::cout << "a Corolla and Camry are the same.\n";

	if (corolla != camry)
		std::cout << "a Corolla and Camry are not the same.\n";
}

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents)
		: m_cents{ cents }
	{}

	friend bool operator> (const Cents& c1, const Cents& c2);
	friend bool operator<= (const Cents& c1, const Cents& c2);

	friend bool operator< (const Cents& c1, const Cents& c2);
	friend bool operator>= (const Cents& c1, const Cents& c2);
};

bool operator> (const Cents& c1, const Cents& c2)
{
	return c1.m_cents > c2.m_cents;
}

bool operator>= (const Cents& c1, const Cents& c2)
{
	return c1.m_cents >= c2.m_cents;
}

bool operator< (const Cents& c1, const Cents& c2)
{
	return c1.m_cents < c2.m_cents;
}

bool operator<= (const Cents& c1, const Cents& c2)
{
	return c1.m_cents <= c2.m_cents;
}

void greater_less() {
	Cents dime{ 10 };
	Cents nickel{ 5 };

	if (nickel > dime)
		std::cout << "a nickel is greater than a dime.\n";
	if (nickel >= dime)
		std::cout << "a nickel is greater than or equal to a dime.\n";
	if (nickel < dime)
		std::cout << "a dime is greater than a nickel.\n";
	if (nickel <= dime)
		std::cout << "a dime is greater than or equal to a nickel.\n";
}

int main() {
	equal_not_equal();
	greater_less();
}