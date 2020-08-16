#include <iostream>

using namespace std;

/*
It is common to have a refernce or a pointer to a struct (or class).
We can select the member of a struct using the memeber selection operator (.).
*/

struct Person
{
    int age ;
    double weight ;
};

int main()
{
    // Define a person
    Person person ;

    // Member selection using reference to struct.
    // Person is the type that ref0 references.
    Person &ref0{person};
    ref0.age = 69 ;

    cout << person.age << endl ;

    // Equivalently, we can do:
    person.age = 6969 ;
    cout << person.age << endl ;

    // Member selection using pointer to struct.
    // Make a pointer that points to a location holding a Person type. Assign an adress to it.
     Person *ptr{&person} ;

     // However with a pointer we need to derence the pointer first.
     (*ptr).age = 696969 ;
     cout << person.age << endl ;

     // This syntax is prefered.
     ptr->age = 69696969 ;
     cout << person.age << endl ;

     cout << endl << "Rule: When using a pointer to access the value of a member, use operator-> instead of operator. (the . operator)" << endl ;
    return 0;
}
