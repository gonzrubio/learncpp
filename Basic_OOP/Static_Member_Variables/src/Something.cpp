#include "Something.h"
#include <iostream>

void Something::printValue() const {
	std::cout << s_value << std::endl;
}

int Something::s_value{ 1 }; // defines the static member variable. Definition is in the global scope.
