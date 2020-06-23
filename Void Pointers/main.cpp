#include <iostream>

/*
    Avoid using unless absolutely necessary, as they effectively
    allow you to avoid type checking.
*/

using namespace std;

struct Something
{
    int n ;
    float f ;
};

int main()
{
    Something sValue ;
    Something *ptrStruct{&sValue} ;

    // We can acess members with pointers
    ptrStruct->n = 69 ;
    cout << sValue.n << endl ;

    void *ptrVoid{&sValue} ;

    // Need to explicitly cast to another pointer type before being dereferenced.
    int *ptrInt{ static_cast<int*>(ptrVoid) } ;

    cout << *ptrInt << endl ;

    cout << endl << "What is the difference between a void pointer and a null pointer?" << endl ;
    cout << endl << "A void pointer is a pointer that can point to any type of object but doesnt" << endl ;
    cout << "know what type of object it is pointing to and must be explicitly cast into another type before derferencing." << endl ;
    cout << "A null pointer is a pointer that is not pointing at any adress. A void pointer can be a null pointer." << endl ;

    return 0;
}
