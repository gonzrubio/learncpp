/* Review of static keyword uses */
// Recall that static variables keep their values and are not destroyed even when they go out of scope.
// Static variables keep their values across multiple function calls.

/* Static member variables */
// Static member variables share their value across all objects of that class.

/* Static member variables are not associated with class objects */
// We can access the static member variables through objects of that class. However, static member variables
// exist even if no object of that class has been instantiated. Like global variables, static member variables
// exist when the program starts and destroyed when the program ends. It is better to think of static member variables
// as variables belonging to the class rather than a particular instance of the class.
// Static member variables are acessed as follows: ClassName::member_variable (after it has been defined).
// Acessing static member variables through the scope resolution operator is prefered over acessing them
// through instances of that class.

/* Defining and initialiing static memebr variables */
// When we declare a static member variable inside a class, we tell the compiler of the existance of 
// of a static member variable identifier. We do not define it, it serves as a forward declaration.
// We explicitly define the static member variables outside the class in the global namespace.
// Static member variablesa are not subject to acess controls. They can be declared and initialized even if they
// are declared as private or protected in the class. They are defined in the implementation code file for the class.

/* Example of static member variables */
// A good example is assigning unique IDs to every instance of the class.

#include "ID_generator.h"
#include "Something.h"
#include <iostream>

void ex1() {
    Something first; // Instantiate an object of Something type.
    Something second; //  "" "" .

    first.printValue();
    second.printValue();

    first.s_value = 2;

    first.printValue();
    second.printValue();

    // Not accessing any instance of the class. Preferred method for acessing static member variables.
    Something::s_value++;

    first.printValue();
    second.printValue();
}

void ex2() {
    ID_generator first;
    ID_generator second;
    ID_generator third;

    std::cout << first.getId() << '\n';
    std::cout << second.getId() << '\n';
    std::cout << third.getId() << '\n';
}


int main()
{
    ex1();
    ex2();

    return 0;
}
