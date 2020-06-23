#include <iostream>
#include <algorithm>
#include <array>
#include <string>

/*
    The functionality provided in the algorithms library falls into one of three categories:

        1) Inspectors - Used to view (not modify) the data in conatiners (ie. Searching and Counting).
        2) Mutators - Used to modify data in a container (ie. sorting and shuffling).
        3) Facilitators - Used to generate a result based on values of the data memebers. For example
        objects that multiply values, or objects that determine what order pairs should be in.
*/

void printArray(std::array<int,3> &arr)
{
    std::cout << "The array is: " ;
    for (element : arr)
        std::cout << element << " " ;
    std::cout << std::endl ;
}

void findTest()
{
    // std::find searches (linear comparisson O(n)) a value in a container. Takes in a interator
    // to the first element in the conatiner and an iterator to the second element in the cotainer
    // and a value to search for. It returns an iterator pointing to the element (if found) or the
    // end of the container (if not found).

    std::array<int,3> arr{13,69,420} ;
    printArray(arr) ;

    std::cout << "Enter an integer to search for and another to replace it with: " << std::endl ;
    int lookfor{0} ;
    int replacewith{0} ;
    std::cin >> lookfor ;
    std::cin >> replacewith ;

    // Use type inference to deduce the type of the iterator found.
    auto found{ std::find(arr.begin(), arr.end(), lookfor) } ;

    if (found != arr.end())
    {
        std::cout << "Found: " << *found << std::endl ;
        *found = replacewith ; // Override the element
    }
    else
    {
        std::cout << "Did not find: " << lookfor << std::endl ;
    }
    printArray(arr) ;
}

bool containsNut(std::string str)
{
    return (str.find("nut") != std::string::npos) ;
}

void findIfTest()
{
    // Finds the first occurence. Works like std::find but instead of passing a value
    // we pass in a callable object, such as a function pointer (or lambda) that checks
    // if a match is found. std::find_if will call this function for every element in the cointainer
    // until a matching element is found (or there are no more remaining element to check.

    std::array<std::string, 4> arr{ "peanut", "banana", "walnut", "lemon" };
    // Scan our array to see if any elements contain the "nut" substring
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }
}

void countTest()
{
    std::array<std::string,4> arr{ "peanut", "banana", "walnut", "lemon" } ;
    auto total{ std::count_if(arr.begin(), arr.end(), containsNut) } ;
    printf("Counted %d nuts",total) ;

}

bool greaterThan(int a, int b)
{
    return (a > b) ;
}

void testSortCustom()
{
    std::array<int,4> arr{13,420,69,6969} ;
    std::cout << "The array is: " ;
    for (element : arr)
        std::cout << element << " " ;
    std::cout << std::endl ;

    std::sort( arr.begin(), arr.end(), greaterThan ) ;
    std::cout << "The array is: " ;
    for (element : arr)
        std::cout << element << " " ;
    std::cout << std::endl ;

    // Because sorting in descending order is so common we can use std::greater.
    // std::sort( arr.begin(), arr.end(), std::greater{} ) ;
    // std::greater{} uses curly braces because it is not a callable function. It is
    // a type, we need to instantiate and object of that type to use it. The curly braces
    // instantiate an anonymous object of that type (which then gets passed as an argument
    // to std::sort).
}

void doubleInt(int &a)
{
    a *= 2 ;
}

void testForeach()
{
    // std::for_each takes a list as an input and applies a custom function to each element.
    std::array<int,3> arr{13,69,420} ;
    printArray(arr) ;

    std::for_each( arr.begin(), arr.end(), doubleInt) ;
    printArray(arr) ;
}


int main()
{
    // findTest() ;
    // findIfTest() ;
    // countTest() ;
    // testSortCustom() ;
    // testForeach() ;

    return 0;
}
