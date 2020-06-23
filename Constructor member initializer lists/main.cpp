#include <iostream>
#include <cstdint> // for std::uint_fast8_t
/*
    Recall...
    C++ provides copy (=), direct (), and brace {} initialization, and copy assignment (=).
    Prefer direct brace initialization (direct uniform initialization) whenever
    possible, for performance reasons and consistent notation.
    {} direct brace initialization (uniform initialization) will assign the default type value
    for that variable being initialized.
    Allways initialize variables upon creeation. AKA always use uniform initialization.

    Rule: Use member initializer lists to initialize your class member variables instead of assignment.
    As this is the ONLY way to initialize members that require values upon unitialization such as const
    and reference members (remeber that const and reference variables must be initialized upon declaration).
*/

class Something
{
private:
    int m_value1 ;
    double m_value2 ;
    char m_value3 ;
public:
    // Constructor using initialization list:
    Something(int value1, double value2, char value3 = 'c')
        : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 } // Directly initialize member variables.
    {
        // No need for assignment here.
    }
    void print()
    {
        std:: cout << "(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n" ;
    }
};

class A
{
public:
    A(int x){std::cout << "A " << x << "\n" ; }
};

class B
{
private:
    A m_a ;
public:
    B(int y) : m_a{ y-1 }
    {
        std::cout << "B " << y << "\n" ;
    }
};

void ex0()
{
    Something something{1,2.2} ;
    something.print() ;

    /// Initializing memeber variables that are classes"
    B b{5} ;
    // When variable b is constructed, the B(int) constructor is called
    // with value 5. Before the body of the B(int) constructor executes,
    // m_a is initialized with uniform initialization and value 4 is passed.
    // The body of the constructor A() executeds anthe control returns to the body
    // of the B() constructor, printing "5".
}

class RGBA
{
public:
    // A type alias saves typing and makes easier to maintain.
    using component_type = std::uint_fast8_t ;
private:
    component_type m_red ;
    component_type m_green ;
    component_type m_blue ;
    component_type m_alpha ;
public:
    RGBA(component_type red=0,component_type green=0, component_type blue=0, component_type alpha=255)
        : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
    {
    }
    print()
    {
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << "\n" ;
    }
};

void ex1()
{
    // Write a class named RGBA that contains 4 member variables of
    // type std::uint_fast8_t named m_red, m_green, m_blue, and m_alpha
    //(#include cstdint to access type std::uint_fast8_t).

    // Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha.

    // Create a constructor that uses a member initializer list that allows
    // the user to initialize values for m_red, m_blue, m_green, and m_alpha.

    // Include a print() function that outputs the value of the member variables.
    RGBA teal{ 0, 127, 127 } ;
    teal.print() ;
}

int main()
{
    //ex0() ;
    ex1() ;

    return 0;
}
