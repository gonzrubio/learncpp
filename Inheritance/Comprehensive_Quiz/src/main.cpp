/*

*/

#include "Apple.h"
#include "Banana.h"
#include "GrannySmith.h"
#include <iostream>

void Q2() {
	Apple a{ "red" };
	Banana b{};
	GrannySmith c;

	std::cout << "My " << a.get_name() << " is " << a.get_color() << ".\n";
	std::cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
	std::cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";
}

int main() {
	Q2();
}