#include <iostream>

using namespace std;

void isPtrNull(int *ptr)
{
    if (ptr)
        cout << "This pointer is non-null: " << ptr << endl;
    else
        cout << "This is a null pointer: " << ptr << endl ;
}

int main()
{
    cout << "Like normal variables, pointers are not initialized when instantiated." << endl;
    cout << "Unless a value is assigned, pointers will point to some garbage adress by default." << endl;
    int *ptr69;
    cout << "For example 'int *ptr69;' will point to: " << ptr69 << endl ;

    cout << endl << "Besides memory adresses, pointers can hold a null value. Meaning that they are not " << endl ;
    cout << " pointing at anything. A pointer holding the null value is called a null pointer." << endl ;

    // Declare and initialize a null pointer.
    double *nllptr{nullptr} ;
    cout << "'int *nllptr{nullptr}; is a null pointer." << endl ;

    cout << "Pointers convert to boolean true if they are non-null and the boolean false if they are null." << endl ;

    //testisPtrNull() ;
    int *a ;
    isPtrNull(a) ;
    int *b{nullptr} ;
    isPtrNull(b) ;



    return 0;
}
