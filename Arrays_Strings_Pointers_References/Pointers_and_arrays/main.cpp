#include <iostream>

using namespace std;

void arrayDecay()
{
    int array[6]{1,2,3,4,5,6} ;
    cout << "Element 0 has adress: " << &array[0] << endl ;
    cout << "The array decays (is implicitly converted) to a pointer holding adress: " << array << endl ;
    cout << "Arrays are of type 'data_type var_nam[num_elements]'. Pointers to the array are of type 'data_type *'" << endl ;
    cout << "We can dereference the array to get its first elelment (*array returns array[0]): " << *array << " = " << array [0] << endl ;
    cout << "This allows us to effectively treat fixed arrays as pointers in most cases." << endl ;
    cout << "We are not actually dereferencing the array. The fixed array gets implicitly converted (decays) into a pointer holding the adress of the first element." << endl ;

    cout << "We can also assign a pointer to point at the array:" << endl ;
    int *temp{array} ;
    cout << temp << " = " << array << " and " << *temp << " = " << array[0] << endl ;
    cout << "This works because the array decays into a pointer of type int *, and our pointer (also of type int *) has the same type." << endl ;
}

void arrayPointerSizeoff()
{
    int array[3]{1,2,3} ;
    int *arrptr{array} ;
    cout << "The size of the arrays is: " << sizeof(array) << endl ;
    cout << "The size of the pointer the array decays to is: " << sizeof(arrptr) << endl ;
    cout << "sizeof(array) = number of elements * size of element." << endl ;
    cout << "sizeof(arrptr) = size of memory adress in bytes." << endl ;
    cout << "A fixed array knows how long the array it is pointing to is. A pointer to the array does not." << endl ;
}

void arraysToFunctions(int *aray)
{
    cout << sizeof(aray) << "Prints the size of a pointer, not the array" << endl ;
    cout << "This is equivalent to foo(int aray[]) since fixed arrays will decay to a pointer." << endl ;
    cout << "Arrays decay to pointers when passed to a function." << endl ;
}

void changeArray(int *ptr)
{
    cout << "In changeArray()" << endl ;
    *ptr  = 69 ;

}

int main()
{
    arrayDecay() ;
    arrayPointerSizeoff() ;

    // Declare and initialize a fixed size array.
    int arr[]{1,2,4,5,7,8,3,6,9} ;
    arraysToFunctions(arr) ;

    cout << "arr[0] has the value: " << arr[0] << endl ;
    changeArray(arr) ;
    cout << "arr[0] has the value: " << arr[0] << endl ;


    return 0;
}
