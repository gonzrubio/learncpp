/*
In C++, a throw statement is used to signal that an exception or error case has occurred.
Signaling that an exception has occurred is also commonly called raising an exception.

In C++, we use the try keyword to define a block of statements (called a try block).
The try block acts as an observer, looking for any exceptions that are thrown by any of
the statements within the try block.

The catch keyword is used to define a block of code (called a catch block) that handles
exceptions for a single data type.

Try blocks and catch blocks work together -- A try block detects any exceptions that are
thrown by statements within the try block, and routes them to the appropriate catch block
for handling. A try block must have at least one catch block immediately following it, but
may have multiple catch blocks listed in sequence.

Once an exception has been caught by the try block and routed to a catch block for handling,
the exception is considered handled, and execution will resume as normal after the catch block.

Exceptions of fundamental types can be caught by value, but exceptions of non-fundamental
types should be caught by const reference to avoid making an unnecessary copy.

Just like with functions, if the parameter is not going to be used in the catch block,
the variable name can be omitted. This can help prevent compiler warnings about unused variables.

Note that the compiler will not perform implicit conversions or promotions when matching
exceptions with catch blocks.
*/

#include <iostream>
#include <string>

int main() {
    try {
        // Statements that may throw exceptions you want to handle go here
        throw - 1; // here's a trivial example
    }
    catch (int x) {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (double) { // no variable name since we don't use the exception itself in the catch block below
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double" << '\n';
    }
    catch (const std::string& str) { // catch classes by const reference
        // Any exceptions of type std::string thrown within the above try block get sent here.
        std::cout << str << "\n";
        std::cerr << "We caught an exception of type std::string" << '\n';
    }
    std::cout << "Continuing on our merry way\n";
}
