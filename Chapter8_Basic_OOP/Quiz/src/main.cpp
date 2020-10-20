/* Summary */
// Classes allow us to create cutom data types that bundle data and functions together. 
// Members of the class are accessed using the . operator or ->  if accessing through a pointer.
// Encapsulation is the process of making all the member data private, so they can not be accessed directly.
// Member initializer lists allows us to initializa our member variables throught the constructor.
// Constructors are allowed to call other constructors (delegating constructors/constructor chaining).
// To avoid circular depedencies, put class definitions in a header file and member function definitions
// in a .cpp file of the same name as the class.
// Member functions should be made const if they do not modify the state of the object. Const class objects
// can only call const member funcitons.
// Static member variables are shared across all class objects and should be accessed through the scope resolution operator.
// Static member functions are member functions that have no *this pointer. Static member functions
// can only acess static member variables.
// We can create anonymous class objects for the purpose of evaluating in an expression, or passing a return value.

#include "Point2d.h"
#include <iostream>

void question1() {
    // Change function distanceTo from a member function to a non-member friend function that
    // takes two Points as parameters. Also rename it “distanceFrom”.
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
}

int main()
{
    question1();
}
