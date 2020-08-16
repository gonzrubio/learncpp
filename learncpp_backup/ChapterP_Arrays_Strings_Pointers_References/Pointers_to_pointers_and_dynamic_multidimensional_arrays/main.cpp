#include <iostream>

/*
    A pointer to a pointer is a pointer that holds the adress of another pointer.
    You can not set a pointer to a pointer directly to a value. This is because the
    adress-of operator (operator&) expects an lvalue, but &value is an rvalue.
    However, a pointer to a pointer csan be set to null.

    Uses: pointers to pointers are used to dynamicallyh allocate and array of pointers.
*/

using namespace std;

void ptrtoptr()
{
    cout << "Inside ptrtoptr() ..." << endl ;
    int tmp{69} ;
    int *ptr{&tmp} ;        // Pointer to an int.
    int **ptrptr{&ptr} ;    // Pointer to a pointer.

    cout << "Value: tmp = " << tmp << endl ;
    cout << "Adress: &tmp = " << &tmp << " = ptr = " << ptr << endl ;
    cout << "Dereference: *ptr = " << *ptr << " = tmp = " << tmp << endl ;
    cout << "Pointer to pointer: ptrptr = " << &ptr << " != &tmp = " << &tmp << " = ptr" << endl ;
    cout << "Dereference pointer to pointer: **ptrptr = " << **ptrptr << " = *ptr = " << *ptr << " = tmp = " << tmp << endl ;
    cout << "Exited ptrtoptr() ..." << endl << endl ;
}

void arraysPointers()
{
    cout << "Inside arraysPointers() ..." << endl ;
    // Dynamically allocate and array holding pointers.
    // A pointer pointing to an array of pointers.
    int **arr0{ new int*[10] } ; // Allocate an array of 10 pointer. The array elements are of type "pointer to integer".
    // Above: an array of length 10 where the element type is pointer to int. Thus, we have a pointer to pointers.

    // Dynamically allcate memory for an array. The pointer points to an array where the elements are of type int.
    int *arr1{ new int[10]{}} ;
    delete[] arr1 ; // Dont forget to free memeory.

    // The first assignment is a pointer pointing to an array with elements of type pointer to int.
    // The second example is a pointer pointing to an array with eleemnts of type int.
    cout << "Exited arraysPointers() ..." << endl << endl ;

}

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
     return (row * numberOfColumnsInArray) + col;
}


int main()
{
    ptrtoptr() ;
    arraysPointers() ;

    // Useful to dynamically allocate mutidimensional arrays
    int rows{ 10 } ;
    int cols { 5 } ;
    int **array = new int*[rows];                 // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < rows; ++count)
        array[count] = new int[cols];             // these are our columns

    // Now deallocate (free memory)
    for (int count = 0; count < rows; ++count)
        delete[] array[count];
    delete[] array; // this needs to be done last

    // It is possible to make non-rectuangular arrays.
    int **array2 = new int*[rows]; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < rows; ++count)
        array2[count] = new int[count+1]; // these are our columns

    // Now deallocate (free memory)
    for (int count = 0; count < rows; ++count)
        delete[] array2[count];
    delete[] array2 ; // this needs to be done last

    // Flatten array
    int *array3 = new int[rows * cols]; // a 10x5 array flattened into a single array
    delete[] array3 ;

    // index in flattened array:
    //getSingleIndex(...) ;

    return 0;
}
