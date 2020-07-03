#include <iostream>
#include <vector>

/*
Recall ...

std::array provides the functionality of built-in fixed arrays
in a safer more usable form.

Analogously, the std::vector provides functionality that makes
working with dynamic arrays safer and easier.

Conclusion ...

Because std::vector can handle its own memeory management, preventing
memory leaks,remeber their length, and can easily be resized, using
std::vector is prefered whenever dynamic arrays are needed.
*/

void introVector()
{
    // std::vector provides dynamic array functionality that handles
    // its own memory management.
    // Do not neet to specify (in initialized or unitialized) array length
    // at compile time. std::vector will dynamically allocate memory as requested.

    std::vector<int> arr ;            // No need to specify length at initialization.
    std::vector<int> arr0(2) ;        // Single vector of size 2.
    std::vector<int> arr1{69,420} ;   // Can use uniform initialization to initialize an array.

    // Unlike built-in dynamic arrays, which don't know the size of the array thery are
    // pointing to , std::vector keeps track of it's length.
    printf("Size of arr = %d \n", arr.size()) ;
    printf("Size of arr0 = %d \n", arr0.size()) ;
    printf("Size of arr1 = %d \n", arr1.size()) ;

    printf("arr1 = ") ;
    for (int element : arr1)
        printf("%d ",element) ;

    arr0[0] = 13 ;       // No bounds checking.
    arr0.at(1) = 13 ;    // Does bounds checking.

    // The vector will not automatically resize if we request an element that is out of bounds.
    // However, we can assign values to a std:: vector using an initializer-list. The std::vector
    // will self-resize to match the number of elements provided.
    arr = {13,13,13} ;
    printf("\nSize of arr = %d \n", arr.size()) ;  //Array length is now 3.

    // vector is safes since when it goes out of scope, it will automatically deallocate the
    // memory it controls (if necessary) preventing memory leaks.

    // Just like with std::array, the size() member function returns a value of nested type size_type.
    // The example above: std::vector<int>::size_type, which is an unsigned integer.
}

void resizingVector()
{
    // Resizing a built-in dynamically allocated array is complicated.
    // Resizing a std::vector is done with the resize() method (member function).

    std::vector<int> vec{1,2,3} ; // Declare a std::vector of size 0.
    printf("Size of vec = %d \n", vec.size()) ;

    printf("vec = ") ;
    for (int element : vec)
        printf("%d ",element) ;

    vec.resize(5) ;       // The std::vector is now of size 5.
    printf("\nSize of vec = %d \n", vec.size()) ;

    printf("vec = ") ;
    for (int element : vec)
        printf("%d ",element) ;

    // 1) When the std::vector is resized, te existing elements are preserved.
    // 2) New elements are initialized to their default type which is 0 for integers.

    vec.resize(3) ;         // Can resize std::vector to be smaller.
    printf("\nvec = ") ;
    for (int element : vec)
        printf("%d ",element) ;

    // Resizing a vector is computationally expensive. Strive to minimize the times to do so.
    // Initialize to default values of we know the size but not the values.
    std::vector<int> vec1(6) ;
    printf("\nThe length of vec1 is: %d \n" , vec1.size()) ;
    printf("vec1 = ") ;
    for (int element : vec1)
        printf("%d ", element) ;
}

int main()
{
    introVector() ;
    resizingVector() ;

    return 0;
}
