#include <iostream>
#include <string>

using namespace std;

/*
    for-each loop, also called range-based for-loop provides a asfaer way to iterate through list-type structures.
    Like vectors, linked lists, trees and maps.

    The for-each statement has a syntax that looks like this:
    for (element_declaration: array)
        statement ;

    The loop iterates through each element in array, assigning the curretn array element
    to the variable declared in element_declaration.
    Element declaration should have the same type as the array elements (tip: auto keyword).

    Note: a variable that assumes the proper type based on the value we are initializing it with.
    When initializing a variable, the auto keyword can be used in place of the type to tell the compiler to infer
    the varibale's type form the initializer's type. This is called type inference (or type deduction).

    Note: To iterate through an array, for-each need to know how big the array is (array size).
    Arrays decay into a pointer so we dont know their size. ie. when passing an array (decays to pointer) to a function.
    Can not get the index of the current element.

    Summary: Should be preferred over standar for loops when possible like when we need to iterate through an array sequentially.


*/

void bestScore()
{
    constexpr int scores[]{84,92,76,81,56} ;
    constexpr int numStudents{sizeof(scores)/sizeof(scores[0])} ;

    int maxScore{scores[0]} ;

    for (int ii = 1 ; ii < numStudents ; ii++)
    {
        if (maxScore < scores[ii])
        {
            maxScore = scores[ii] ;
        }
    }
    cout << "The highest score is: " << maxScore << endl << endl ;
}

void printFib()
{
    constexpr int fib[]{0,1,1,2,3,5,8,13,21,34,55,89} ;
    for (auto fibNumber: fib) // type is auto so fibNumber has its type (int) inferred from the array.
    {
        cout << fibNumber << " " ;
    }
    cout << endl ;
}

void references()
{
    // In for-each loops element declarations, use references (if want to make changes) for
    // non-fundamental data types (performance). Use const references for read-only fashion.

    cout << "Pass by reference and modify:" << endl ;
    string names[]{"anna","lola","donna"} ;
    for(auto &name: names)
    {
        cout << "before: " << name << endl ;
        name = "69" ;
        cout << "after: " << name << endl ;
    }

    cout << "const pass by reference for read only:"  << endl ;
    for (const auto &name:names)
    {
        cout << "name: " << name << endl ;
    }
}

void bestScoreForEach()
{
    constexpr int scores[]{84,92,76,81,56} ;
    int maxScore{0} ;

    for (auto student : scores)
        if (maxScore < student)
            maxScore = student ;
    cout << "The highest score is: " << maxScore << endl ;
}

void quiz()
{
    string names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" } ;
    cout << "Enter a name: " ;
    string username{} ;
    cin >> username ;

    bool found { false } ;

    for (const auto &name : names)
    {
        if (name == username)
        {
            found = true ;
            break ;
        }
    }

    if (found)
        cout << username << " was found." << endl ;
    else
        cout << username << " was not found." << endl ;
}

int main()
{
    bestScore() ;
    printFib() ;
    references() ;
    bestScoreForEach() ;
    quiz() ;

    return 0 ;
}
