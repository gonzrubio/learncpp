#include <iostream>
#include <string>
#include <algorithm> // for std::sort

using namespace std;

/*
    Unlike fixed arrays where the size must be known/fixed at compile time,
    dynamically allocating an array allows us to choose an array length at run time.
    ie. data_type variable_name[] ; Would cause compile error because size of array is not know at compile time.
*/

void first()
{
    int len ; // Length of array. Declaring it without initializing it, assigns a garbage value to it.
    cout << "Enter the number of elements in the array :" ;
    cin >> len ; // We change the value of len from garbage to the user input.

    // Create a pointer variable holding int type. new int[] request memory from the heap.
    // The syntax belows initializes the dynamic array to 0 via {}.
    int *arr{new int[len]{}} ;

    cout << "I just allocated an array of length " << len << endl ;

    // Indexing is equivalent to pointer adition and dereferencing
    cout << "The last value by default is: " << arr[len-1] << endl ;
    arr[len-1] = len ;
    cout << "The last value after initializing is: " << arr[len-1] << endl ;
    cout << "The first element is allocated at: " << &arr[len-1] << endl ;

    // It is crucial to free up memory before exiting function otherwise we will get memory leakage.
    // array from of delete. Using the scalar form of delete will cause undefined behabiour like memoery leak,
    // data corruption, crashers, or other problems.
    delete[] arr ;


    // No need to set make the pointer a null pointer since it will go out of scope after leaving this function.
    // Must free up memory specififcallly since the pointer will go out of scope and wont be able to access that location.
    // arr = nullptr ;
}

int getNameCount()
{
    int numNames{} ;
    cout << "How many names would you like to enter? " ;
    cin >> numNames ;

    return numNames ;
}

// To return pointers from a function: array_element_type * function_name()
// Alhtough we dont use it here.
void getNames(string *nameArr,int numNames)
{
    // Prompt the user to enter each name.
    for (int ii = 0 ; ii < numNames ; ++ii)
    {
        string temp{} ;
        cout << "Enter name #" << ii+1 << ": " ;
        cin >> temp ;
        nameArr[ii] = temp ;
    }
}

void printSorted(string *nameArr, int numNames)
{
    sort(nameArr,nameArr+numNames) ;

    cout << "The names you entered are:" << endl ;
    for (int ii = 0 ; ii < numNames ; ii++)
    {
        cout << nameArr[ii] << endl ;
    }
}

int main()
{
    /*
    first() ;

    // Declare and initialize a dynamic array holding integers.
    int fixedArr[]{69,69,69} ;
    int *dynArr{ new int[3]{69,69,69} } ;
    cout << fixedArr[1] << endl ;
    cout << dynArr[1] << endl ;

    // Free up memory.
    delete[] dynArr ;
    */

    // Ask the user how many names they wish to enter.
    int numNames{ getNameCount() } ;

    // Dynamically allocate the array.
    //Remeber to delete memeory after use.
    string *nameArr{ new string[numNames]{} } ;

    // Get names.
    getNames(nameArr, numNames) ;

    // Print out sorted names.
    printSorted(nameArr, numNames) ;

    // Free up memory.
    delete[] nameArr ;

    return 0;
}
