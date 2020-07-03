#include <iostream>
#include <array>
#include <iterator> // for std::begin and std::end

// using namespace std ;

// An iterator is an object designed to traverse through an object providing
// access to the elements along the way.
// A container may provide different kinds of iterators depending on the desired traversal.

void demoIterations()
{
    // Declare and initialize an std::array.
    std::array<int,3> data{13,63,420} ;
    int len{data.size()} ;

    printf("The elements in the std::array of length %d are: \n", len) ;
    printf("While-loop with explicit index ...\n") ;
    int idx{0} ;
    while (idx < len)
    {
        printf("%d ",data[idx]) ;
        ++idx ;
    }

    printf("\nFoor-loop with explicit index ...\n") ;
    for (int idx = 0 ; idx < len ; idx++)
    {
        printf("%d ",data[idx]) ;
    }

    // For sequential containers (elements consecutive in memeory)
    printf("\nFoor-loop with pointer ...\n") ;
    //for (int *ptr{&data[0]}; ptr < (&data[0] + len); ptr++)
    for (int *ptr{&data[0]}; ptr < (&data[len]); ptr++) // Equivalen
    {
        printf("%d ",*ptr) ;
    }

    // Use iterators. Work for all data structures.
    printf("\nRange based Foor-loop ...\n") ;
    for (element : data)
    {
        printf("%d ",element) ;
    }
}

void pointerAsIterator()
{
    std::array<int,3> data{13,69,420} ;
    int len{data.size()} ;
    int *start{&data[0]} ;
    int *last{&data[len-1]} ;
    std::cout << std::endl << "start = " << start << std::endl ;
    std::cout << "last = &data[len-1] = " << last << std::endl ;
    std::cout << "&data[0]+len-1 = " << &data[0]+len-1 << std::endl ;
}

void stdIterators()
{
    std::array<int,3> data{13,69,420} ;
    //int len{data.size()} ;

    //From <iterator>
    // These iterators are pointers to the fisrt and last+1
    // memeory adresses.
    int *start{ std::begin(data) } ;
    int *stop{ std::end(data) } ;

    for (int *kk{start} ; kk < stop ; kk++)
        printf("%d ", *kk) ;
    printf("\n") ;

    for (int element : data)
        printf("%d ", element) ;

    // All data types that have a begin() and end() memeber functions can be
    // used with std::begin and std::end, and are usable in range-based for-loops.
}

int main()
{
    demoIterations() ;
    pointerAsIterator() ;
    stdIterators() ;

    return 0;
}
