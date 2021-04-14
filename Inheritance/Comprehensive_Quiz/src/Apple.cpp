#include "Apple.h"

Apple::Apple(const std::string& color) :
	Fruit{ "apple", color } {
}

Apple::Apple(const std::string& name, const std::string& color) :
	Fruit{ name, color } {
}

