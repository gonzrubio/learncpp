#include <iostream>

using namespace std;

/*
    A reference is a type of variable that acts as an alias to another object or value.
    References generally act identicall to the values they are referencing.
    Reference must be initialized. They must reference something.
    References to non-const values can only be initialized with non-const l-values.
    They can no be initialized with const l-values or r-values.
    References can not be reassigned.
    References can provide easier acces to nested data to keep code cleaner and more readable.

    References are most often used as function parameters. In this context, the reference parameter
    acts as an alias for the argument and no copy of the argument is made into the parameter.
    This leads to better performance if the argument is large or expensive to copy.
    A reference acts as an alias to the argument, A function that uses a reference parameter is able
    to modify the argument passed in. Works similar to a pointer in this regard.

    An l-value is a value that has an adress in memeory so every value is an l-value.
    l-values are values that can only be on the left side of an assignment statement. ie. 5 is not.
    On the left side of the assignment we must have something to represent an adress.
    An r-value is a value that can be assigned to an l-value. They always evaluate to a single value.

    Note: const variables are considered non-modifiable l-values.
    Note: When you dont want  a function to change the argument, use const variables.
    Note: If a given task can be solved using either a references or pointers, references should be preferred.
    Note: References are a bit safer than pointers since there is no risk of dereferencing a null pointer.
    Note: Pointers should only be used in situations when references are not sufficient (such as dynamically allocating memory.)

    Rule: Pass non-pointer, non-fundamental data type variables (such as structs) by (const) reference.
    Rule: Pass fundamental data types by value, unless the function need to change them.
*/

void to69(int &tmp)
{
    cout << "Inside function to69().." << endl ;
    cout << "Received: " << tmp << endl ;
    tmp = 69 ;
}

int main()
{
    int a{69} ;     // Normal non-constant value.

    // In this context it  does not mean adress of. Means reference to.
    int &b{a} ;   // b is a reference to a.
    int &c{b} ;   // c is also a reference to a.

    cout << "a = " << a << endl ;
    cout << "b = " << b << endl ;
    cout << "c = " << c << endl ;

    cout << "&a = " << &a << endl ;
    cout << "&b = " << &b << endl ;
    cout << "&c = " << &c << endl ;
    cout << "The examples above show that the reference variable acts as an alias." << endl ;

    a = 6969 ;
    cout << "Changed a to 6969" << endl ;
    cout << "b = " << b << endl ;
    cout << "c = " << c << endl ;

    cout << endl << "In main()... a = " << a << endl ;
    to69(a) ;
    cout << "Back to main()... a = " << a << endl ;

    return 0;
}
