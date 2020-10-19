/* Const classes */
// Class objects can also be made constant by using the const keyword.
// Tip: Make class objects const when you are sure they will not be modified after creation

/* Const member functions */
// Const class objects can only call const member functions. A const member function is a member function that
// guarantees it will not modify the object or call any non-const member function that could modify the const object.
// Syntax for const member functions: return_type foo() const {body .. return_value}. 
// For const member functions defined outside the class definition, the const keyword must be included in both the 
// function prototype in the class definition and in the function definition (implementation).
// Attempta to change a member variable or to call non-const member functions by a const member function causes compiler error.
// Rule: Make const any member functions that do not modify the state of the class object so that it can be called by const class objects.
// Note: Constructors can not be made const.

/* Const references */
// Although instantiating const class objects is a common way to create const objects, it is more common to instantiate
// a const class object by passing an object to a function by const reference. This is more efficient as it does not make
// a copy of the object. 

/* Overloading const and non-const function */
// It is possible to overload a function in such way to have a const and non-const versions.

/* Summary */
// Passing objects by const reference is quite common to avoid making copies or modifying the state of the object.
// Therefore, classes should be const-friendly. Member functions that do not alter the state of the class object should be made const.

#include "Date.h"
#include <iostream>

void printDate(const Date &date) { 
    // note: We're passing date by const reference here to avoid making a copy of date.
    std::cout << date.getDay() << '/' << date.getMonth() << '/' << date.getYear() << std::endl;
}

int main()
{
    // Instantiate Date type object.
    Date date{ 20, 4, 69 };

    // Print the date of Date.
    printDate(date);
}
