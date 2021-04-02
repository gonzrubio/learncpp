/*
Using a friend function to overload an operator is convenient because it gives you direct access
to the internal members of the classes you’re operating on. However, if you don’t need that access,
you can write your overloaded operators as normal functions.

Because the normal and friend functions work almost identically (they just have different levels
of access to private members), we generally won’t differentiate them. The one difference is that
the friend function declaration inside the class serves as a prototype as well. With the normal
function version, you’ll have to provide your own function prototype.

In general, a normal function should be preferred over a friend function if it’s possible to do so
with the existing member functions available (the less functions touching your classes’s internals,
the better). However, don’t add additional access functions just to overload an operator as a normal
function instead of a friend function!
*/

#include "Cents.h"
#include <iostream>

int main() {
    Cents cents1{ 6 };
    Cents cents2{ 8 };
    Cents cents_sum{ cents1 + cents2 };
    std::cout << "I have " << cents_sum.get_cents() << " cents.\n";
}