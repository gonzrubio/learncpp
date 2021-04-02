#include <iostream>

using namespace std;

int main()
{
    // Instantiate a variable of type in.
    // Name that location in memory (variable/identifier).
    int x ;
    cout << "The name of the piece of memory is x." << endl ;
    cout << "The memory adress of the piece of memory named x is: " << &x << "." << endl ;
    cout << "We call (&) the 'adress-of' operator and it returns the adress of x." << endl ;
    cout << "We instantiated x but didn't assign any value to it so will have its default value: " << x << "." << endl ;
    cout << "We can access the value located at memory location " << &x << " using the dereference operator (*) as *(&x) = " << *(&x) << "." << endl ;

    cout << "Note: The multiplication operator (*) is binary. The dereference operator (*) is unary." << endl ;
    cout << endl << "A pointer is a variable that holds a memory adress as its value and can be written as *x." << endl ;

    cout << endl << "A pointer is declared lika a normal variable but with an asteric preceding the identifier: 'data_type *variable_name;'." << endl ;

    cout << endl << "If a function returns a pointer as the return data type, use this convention: 'return_data_type* foo()'." << endl ;

    int *ptr ; // Declare a pointer. It is not initialized so it contains garbage.
    cout << endl << "Like variables, pointers are not initialized when declared so they will contain garbage." << endl ;
    cout << "The value of *ptr (was declared but not initialized) is: " << *ptr << " and its adress is: " << ptr << " ." << endl ;

    cout << endl << '\t' << "- Pointers can only hold memory adresses." << endl ;
    cout << '\t' << "- When we initialize/assign a value to a pointer, it has to be a memory adresss." << endl ;
    cout << '\t' << "- One of the most common things to do is to assign the adress of a different variable to a pointer." << endl ;

    int v = 5 ; // Declare a varibale (v) of type int and assign the value 5 to it.
    int *ptr1 = &v ; //Declare a pointer variable ptr holding the memory adress of v.
    cout << endl << "v = " << v << "." << endl ;
    cout << "its adress: &v = " << &v << "." << endl ;
    cout << "The pointer variable ptr1 = " << ptr1 << " which is a memory adress." << endl ;
    cout << "We dereference ptr to get its value (should be same as v=5): *ptr1 = " << *ptr1 << endl << endl ;

    cout << "Pointers have a type so they know how to interpret the value held in memory when dereferenced." << endl << endl ;

    cout << "When the adress of variable value is assigned to ptr, the following are true:" << endl ;
    cout << '\t' << "- ptr is the same as &value." << endl ;
    cout << '\t' << " *ptr is treated the same as value." << endl << endl ;

    cout << "What are pointers good for?" << endl ;
    cout << '\t' << "1) Arrays are implemented using pointers. Pointers can be used to iterate through an array as opposed to indices." << endl ;
    cout << '\t' << "2) They are the only way to dynamically allocate memory in C++." << endl ;
    cout << '\t' << "3) They can be used to efficientyl pass large amounts of data to a function without copying it." << endl ;
    cout << '\t' << "4) Thye can be used to achieve polymorphism when dealing with inheritance." << endl ;
    cout << '\t' << "5) They can be used to pass a function as a parameterto another funciton." << endl ;
    cout << '\t' << "6) They can be used to have one struct/class point at another struct/class, to form a chain like linked lists or trees." << endl ;

    return 0;
}
