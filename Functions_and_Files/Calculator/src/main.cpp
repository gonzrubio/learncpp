/* main.cpp : A simple calculator that takes a number, operator and another number as a user input. */

#include "Calculator.h"
#include <iostream>


int main()
{
	/* Get first number from user */
	double a{ getUserInput() };

	/* Get mathematical operation from user */
	char operand{ getMathematicalOperation() };

	/* Get second number from user */
	double b{ getUserInput() };

	/* Calculate result */
	double answer{ calculateResult(a, operand, b) };

	/* Print result */
	printResult(answer);
}
