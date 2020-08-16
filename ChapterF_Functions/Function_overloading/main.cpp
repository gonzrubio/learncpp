#include <iostream>

/*
Function overloading allows to create multiple functions witht he same name as long as
they have different parameters. Using function overloading, we can declare a fucntions
that take in parameters of different types or number of parameters (ie. int, flaot, etc.)

1) Find exact match: Where the argument exactly matches the parameter type of one of one
of the overloaded fucntions.
2) If no exact match is found, try to find one through promotion:
    - Char, unsigned char, and short are promoted to an int.
    - Unsigned short can be promoted int or unsigned int.
    - Float is promoted to double.
    - Enum is promoted to int.
3) If no promotion is possible, find a match through standard conversion
        - Any numeric type will match any other numeric type, including unsigned (ie. int to float).
        - Enum will match the formal type of a numeric type (num to float).
        - Zero will match a pointer type and numeric type (ie. 0 to char* or 0 to float).
        - A pointer will match a void pointer.
4) Find a match through user-defined conversion.
*/


int main()
{
    std::cout << "Use function overloading to make your programs simpler!!" << std::endl ;
    return 0;
}
