#include <iostream>
#include <iterator>

using namespace std;

namespace studentNames
{
    /*
        Integer indeces do not provide much information on the meaning of
        the indices. Solved by setting up an enumerator where one enumerator maps
        to each of the possible array indices.
    */
    enum studentNames
    {
        Kenny, // 0
        Kyle, // 1
        John, //2
        Jojo, // 3
        David, // 4
        maxStudents // 5
    } ;
}

void passValue(int value)
{
    value = 6969 ;
}

void passArray(int array[4], int len)
{
    for (int i = 0 ; i < len ; i ++)
        // array[i] = array[i] + 1 ;
        array[i]++ ;
}

int main()
{

    // Initializing array with enumerator
    int testScores[studentNames::maxStudents] ;
    testScores[studentNames::Kyle] = 69 ;

    cout << "Kyle got " << testScores[studentNames::Kyle] << " on his exam." << endl ;
    cout << testScores[0] << endl ;

    /*
    When passing an array to a function, C++ Does not support pass-by-value on arrays
    since pass-by-value would make a copy of the array and that can be memory expensive
    for large arrays. Instead, the actuall array is passed to the function.
    Therefore functions can directly change arrays.
    */

    int value = 69 ;
    cout << "Before passValue: " << value << endl ;
    passValue(value) ;
    cout << "After passValue: " << value << endl ;

    int len = 4 ;
    int array[len]  = {5,8,5,8} ;

    cout << "Before passArray: " ;
    for (int i = 0 ; i < len ; i++)
        cout << array[i] ;

    passArray(array,len) ;
    cout << endl << "After passArray: " ;
    for (int i = 0 ; i < len ; i++)
        cout << array[i] ;

    /*
    We can determine the length of a fixed array by dividing the size of
    the entire array by the size of an array element.
    */

    cout << endl << "Tis array has: " << sizeof(array)/sizeof(array[0]) << " elements." << endl ;



    return 0;
}
