#include <iostream>

using namespace std;

/*
To summarize, you only need to remember 4 rules, and they are pretty logical:

A non-const pointer can be redirected to point to other addresses.
A const pointer always points to the same address, and this address can not be changed.
A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.
A pointer to a const value treats the value as const (even if it is not), and thus can not change the value it is pointing to.
Keeping the declaration syntax straight can be challenging. Just remember that the type of value the pointer points to
is always on the far left:
*/

int main()
{
    //constexpr int temp{5} ;
    int temp{5} ;
    cout << "temp = " << temp << endl ;

    //int *ptrtemp{&temp} ; // Wont compile. We cant set a non-constant pointer to a constant value.
    int *ptrtemp{&temp} ;
    *ptrtemp = 69 ;
    cout << "temp = " << temp << endl ;
    cout << "The non-constant pointer: " << ptrtemp << endl ;

    // Can make a pointer itself constant
    int *const ptr1{&temp} ;
    cout << "The constant pointer: " << ptr1 << endl ;

    // Just linke normal const variables, they must initialized upon declaration.
    // So it always points to the same direction.

    // It is also possible to have const pointer pointing to a const value.
    // The pointer nor the value can be changed.
    constexpr int constvalue{69} ;
    const int *const constptr{&constvalue};

    cout << "The constant pointer: " << constptr << " is pointing to the constant value: " << constvalue << endl ;

    return 0;
}
