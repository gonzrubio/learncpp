/* Friend Functions */
// A friend function is a function that can access the private members of a class without being a member of that class.
// A friend function may be a regular function or a member function of another class.
// Syntax: friend return_type foo() ; (This is a function protoype).

/* Multiple friends */
// A function can be a friend of multiple classes at the same time.

/* Friend Member functions */
// We can make a single member function a friend: firiend ClassName::member_function();
// Tip: Separate class definitions in header files to make life easy.

/* Summary */
// A friend function or class is a function or clas that can acess the private members of other classes
// as if it were a member of that class. 
// Making a specific member function a friend requires the full definition for the class of the member function
// to have been seen first.

#include "Point3D.h"
#include "Vector3D.h"
#include <iostream>

int main()
{
    // Instantiate Point3D object p. Starts at origin by default. Can print position and move it.
    Point3D p{1.0, 2.0, 3.0};

    // Instantiate Vector3D object v. Starts at origin by default. Can print position.
    Vector3D v{2.0, 2.0, -3.0};

    // print coordinates of p.
    p.print();

    // apply vector to it to move it.
    p.moveByVector(v);

    // print coordinates of p.
    p.print();
}
  