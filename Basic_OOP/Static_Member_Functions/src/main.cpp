/* Static member functions */
// Recall that static member variables are variables that belong to the class rather than to a particular instance of the class.
// We can acces public static member variables using the class name and the scope rsolution operator. If the static member variable
// is private then we would need a public member function to access such variable. Meaning we need to create and instance
// of the clas and acess the static meber variable throught that objects's public member function.
// We can also make member functions static and like static member variables, they do not belong to instances but rather
// to theclass itself. We can now acess the variable throught the class name, scope resolution operator and the public static member function.
// This has the implication that we do not need to instantiate any object. This is the prefered method for accessing private static member variables.

/* Static member funtions have no *this pointer */
// This makes sense since the static member functions are not attached to any object.
// Static member functions can acces other static member variables and functions but not non-static members.
// This is because non-static members are associated to an object. 


#include <iostream>

class IDGenerator {
private:
    static int generator; // declaration of the static member.
public:
    static int getID(); // static member function declaration.
};

int IDGenerator::generator{ 1 }; // sattic member variable definition. We start at ID #1.
int IDGenerator::getID() { return generator++; } // static member function definition.

int main()
{
    for (int i{}; i < 3; i++) {
        std::cout << "ID #: " << IDGenerator::getID() << std::endl;
    }
}
