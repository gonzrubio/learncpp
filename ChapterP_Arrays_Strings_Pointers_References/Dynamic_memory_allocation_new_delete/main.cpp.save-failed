#include <iostream>

using namespace std;

int main()
{
    // Stack overflow ~ 4MB of memory.
    //int array[1000000] ;

    cout << "Runing programs allocate most normal variables in the stack." << endl ;
    cout << "Dynamic memory allocation is a way to request memory from the OS as needed." << endl ;
    cout << "This memory comes from the larger pool of memory called the heap. Managed by the OS." << endl ;

    // The new operator creates an object using that memory (an intgers worth)
    // Then, it returns a pointer containing the adresss of the memory that was allocated.
    int *ptr = new int;
    cout << "Dynamically allocated memory with adress: " << ptr << endl ;
    cout << "The size of the allocated space is: " << sizeof(ptr) << ". An integers worth." << endl ;

    // We can dereference the pointer to access the contents stored in that memory adress located in the heap.
    *ptr = 69 ;
    cout << "Initialized pointer to: " << *ptr << endl ;

    // When we are done with the dynamically allocater variable we need to free the memory for re-use.
    // This process does not delete the variable, it simply returns the memory to the OS makes the pointer a null pointer.
    delete ptr ; // Return the memory pointed to by ptr to the operating system.
    ptr = nullptr ; // set the ptr to be a null pointr.
    cout << ptr << endl ;

    cout << "the deallocated pointer is now a 'dangling pointer'. Deleteing or dereferencing" << endl ;
    cout << "dangling pointers will lead to undefined behaviour."  << endl ;
    cout << "Set danfling pointers to nullptr" << endl ;

    cout << "Deallocating memory can create multiple dangling pointers." << endl ;
    cout << "Try avoiding having multiple pointers point at the same piece of synamic memory." << endl ;

    int *newptr = new int ; // Dynamically allocate an integer.
    int *duplicate{newptr} ; // Other pointer is now pointing at same memory location.

    cout << newptr << " " << duplicate << endl ;

    delete newptr ; // Return memory to the operating system. newptr and duplicate are now dangling pointers.
    newptr = nullptr ; // newptr is now a null pointer. Other is still dangling.

    cout << newptr << " " << duplicate << endl ;
    delete duplicate ;
    duplicate = nullptr ; // Both pointers are now null pointers.
    cout << newptr << " " << duplicate << endl ;

    // null pointers and dynanmic memory allocation.
    // A null pointer says 'no memory has been allocated to this pointer'.
    // Can use conditionals to allocate memory.
    if (ptr)
    {
        delete ptr ;
        cout << "ptr was deleted." << endl ;
    }
    else
    {
        cout << "ptr is null and can be used to allocate memory." << endl ;
    }

// The funciton below causes a memory leak. The pointer goes out of scope when the function is exited.
// However, the memory is still in use by the program. Can acess it since we dont have the pointer for it.
// Memory elak because it eats up space (or memory is leaking).
/*
void doSomething()
{
    int *ptr = new int;
}
*/


// Besides pointers going out of scope, memory leak can also happen when
// the pointer is assigned to another cunk of memory.
/*
int value = 5;
int *ptr = new int; // allocate memory
ptr = &value; // old address lost, memory leak results
*/

// This can be fixed by deleting the pointer before reassigning it.
/*
int value = 5;
int *ptr = new int; // allocate memory
delete ptr; // return memory back to operating system
ptr = &value; // reassign pointer to address of value
*/

// It is also possible to get memory leak by double allocation.
/*
int *ptr = new int;
ptr = new int; // old address lost, memory leak results
*/

// Dynamically allocated memory has no scope and will stay allocated until dealocated
// By user or the programm terminates.
// Do not dereference dangling or null pointers.



    return 0;
}
