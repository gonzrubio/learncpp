/*
In C++, all functions are classified as either non-throwing (do not throw exceptions) or
potentially throwing (may throw an exception).

The noexcept specifier defines a function as non-throwing. To define a function as non-throwing,
we can use the noexcept specifier in the function declaration, placed to the right of the function
parameter list. 

Note that noexcept doesn’t actually prevent the function from throwing exceptions or calling other
functions that are potentially throwing. Rather, when an exception is thrown, if an exception exits
a noexcept function, std::terminate will be called. And note that if std::terminate is called from
inside a noexcept function, stack unwinding may or may not occur (depending on implementation and
optimizations), which means your objects may or may not be destructed properly prior to termination.

Much like functions that differ only in their return values can not be overloaded, functions differing
only in their exception specification can not be overloaded.
*/

#include <iostream>

int main() {

}