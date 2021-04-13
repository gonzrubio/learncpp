/*
In an inheritance (is-a) relationship, the class being inherited from is called the parent class,
base class, or superclass, and the class doing the inheriting is called the child class, derived class, or subclass.

A child class inherits both behaviors (member functions) and properties (member variables) from the
parent (subject to some access restrictions). These variables and functions become members of the derived class.
Child classes are full-fledged classes, meaning the can have their own members that are specific to that class.

It’s possible to inherit from a class that is itself derived from another class. By constructing such
inheritance chains, we can create a set of reusable classes that are very general (at the top) and
become progressively more specific at each level of inheritance.
*/

#include "BaseballPlayer.h"
#include "Employee.h"
#include <iostream>

int main() {
	BaseballPlayer joe;
	joe.m_name = "Joe";
	joe.m_age = 43;
	std::cout << joe.get_name() << " is " << joe.get_age() << " years old.\n";

	Employee dan{};
	dan.m_name = "Dan";
	dan.m_employee_ID = 123456;
	dan.m_hourly_salary = 40.25;
	dan.print_name_and_salary();
}