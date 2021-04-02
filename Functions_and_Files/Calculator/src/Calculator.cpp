#include "Calculator.h"
#include <iostream>

data_t getUserInput() {

	data_t x{};
	std::cin >> x;
	return x;
}

char getMathematicalOperation() {
	char c{};
	std::cin >> c;
	return c;
}

data_t calculateResult(const data_t a, const char c, const data_t b) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
	else if (c == '/') return a / b;
	else return 0;
}

void printResult(const data_t answer) {
	std::cout << answer << std::endl;
}