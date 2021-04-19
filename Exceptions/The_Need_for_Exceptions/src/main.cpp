/*
When writing reusable code, error handling is a necessity. One of the most common ways to
handle potential errors is via return codes.

However, using return codes has a number of drawbacks which can quickly become apparent
when used in non-trivial cases:
First, return values can be cryptic -- if a function returns -1, is it trying to indicate
an error, or is that actually a valid return value?
Second, functions can only return one value, so what happens when you need to return both
a function result and an error code?
Third, in sequences of code where many things can go wrong, error codes have to be checked constantly.
Fourth, return codes do not mix with constructors very well.

Finally, when an error code is returned to the caller, the caller may not always be equipped to
handle the error. If the caller doesn’t want to handle the error, it either has to ignore it
(in which case it will be lost forever), or return the error up the stack to the function that called it.
*/

#include <iostream>

int findFirstChar(const char* string, char ch) {
    const std::size_t stringlength{ strlen(string) };
    // Step through each character in string
    for (std::size_t index = 0; index < stringlength; ++index)
        // If the character matches ch, return its index
        if (string[index] == ch)
            return index;
    // If no match was found, return -1
    return -1;
}

double divide(int x, int y) {
    return static_cast<double>(x) / y;
}

int main() {

}