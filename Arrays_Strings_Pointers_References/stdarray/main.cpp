#include <iostream>
#include <array>
#include <algorithm> // for std::sort

using namespace std;

void intro()
{
   // Wont decay when passed onto a function
   // Just like native implementation of fixed arrays,
   // the array length must be known at compile time.
   array<int,5> myArray{0,10,1,2,3} ;

   // Can acess values using the subscript operator[] (does not do bounds checking).
   cout << myArray[0] << endl ;

   // Can acess elements using the at() function. It does bound checking.
   //cout << myArray.at(6) << endl ; // Out of bouds, will throw an exception.
   cout << myArray.at(4) << endl ;

   // Cleans up itslef when it goes out of scope.
}

void printLength(const array<int,3> &myArray)
{
    // Because std::array wont decay into a pointer, we can use the .size() method within a function.
    // Always pass std::array by reference or const reference. to prevent the compiler from making a copy.
    cout << "The array length is: " << myArray.size() << endl ;
}

void printArray(const array<int,3> &myArray)
{
    // Because the array length is always known, for-each (range-based) for loops work with std::array.
    for (element : myArray)
        cout << element << " " ;
    cout << endl ;
}

void printSorted(array<int,3> &myArray)
{
    sort(myArray.begin(),myArray.end()) ; // Sort the array forwards
    printArray(myArray) ;
    sort(myArray.rbegin(),myArray.rend()) ; // Sort the array backwards
    printArray(myArray) ;
}

void sizeandsorting()
{
    array<int,3> myArray{2,3,1} ;
    printLength(myArray) ;
    printArray(myArray) ;
    printSorted(myArray) ;
    printArray(myArray) ;
}

struct House
{
    int number ;
    int stories ;
    int roomsPerStory ;
};

printHousesinfo()
{
    // Declare an array holding elements of House type.
    //array<House,3> houses = {{{13,1,2},{69,3,4},{420,5,6}}} ;
    array<House,3> houses{ {{13,1,2},{69,3,4},{420,5,6}} } ;

    for (house : houses)
    {
        cout << "House number " << house.number
             << " has " << (house.stories * house.roomsPerStory)
             << " rooms." << endl ;
    }
}

/*void arrayofstruct()
{



}*/

int main()
{
    intro() ;
    sizeandsorting() ;

    // Always use iterators or range-based (for-each) for loops.
    // Always use std::array over built-in fixed arrays.

    printHousesinfo() ;

    return 0;
}
