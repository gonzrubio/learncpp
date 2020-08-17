#include <iostream>
#include <cassert>
/*
    A destructor is a class member function that is executed when an object
    of that class is destroyed.

    Naming:
    1) The destructor must have the same name as the class, preceeded by a tilde (~).
    2) The destructor can take no arguments.
    3) The destructor has no return type.

    Rule 2) implies that there can be one destructor per class as they can not be overloaded.

    Destructors may call other memeber functions since the object isn't destroyed until after the destructor executes.
*/

class IntArray
{
private:
    int *m_arr ;
    int m_length ;
public:
    IntArray(int length) // Constructor
    {
        assert (length > 0) ; // Check for length greater than zero
        m_arr = new int[length]{} ;
        m_length = length ;
    }
    ~IntArray() // Destrcutor
    {
        // Dynamically deleter the previously allocated array.
        delete[] m_arr ;
    }
    void setValue(int index, int value){m_arr[index]=value ;}
    int getValue(int index){return m_arr[index] ;}
    int getLength(){return m_length ; }
};

void ex0()
{
	IntArray ar{10}; // allocate 10 integers
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count+1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	// On the first line we instantiate a new IntArray class object named ar,
	// and pass in a length of 10. This calls the constructor which dynamically
	// allocates memory for the array member. We must use dynamically allocation
	// here because we do no know the length at compile time (the caller decides that).

	// At the end of main, ar goes out of scope. This causes the ~IntArray() destructor to
    // be called, which deleted the array we created with the constructor.
}

class Simple
{
private:
    int m_nID;

public:
    Simple(int nID)
        : m_nID{ nID }
    {
        std::cout << "Constructing Simple " << nID << '\n';
    }

    ~Simple()
    {
        std::cout << "Destructing Simple " << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

void ex1()
{
    // Allocate a Simple on the stack
    Simple simple{ 1 };
    std::cout << simple.getID() << '\n';

    // Allocate a Simple dynamically
    Simple *pSimple{ new Simple{ 2 } };

    std::cout << pSimple->getID() << '\n';

    // We allocated pSimple dynamically, so we have to delete it.
    delete pSimple;

    // Note that “Simple 1” is destroyed after “Simple 2” because we
    // deleted pSimple before the end of the function, whereas simple
    // was not destroyed until the end of main().

    // Global variables are constructed before main() and destroyed after main().

}

int main()
{
    ex0() ;
    ex1() ;

    return 0;
}
