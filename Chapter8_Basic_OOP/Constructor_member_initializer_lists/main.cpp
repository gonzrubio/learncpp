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

    Member initializer lists initialize class member varibales, rather than assignning values to
    them after they are created.
*/

class Something // Custom data type.
{
private:
    int m_value1 ;
    double m_value2 ;
    char m_value3 ;
public:
    // Fix so it works with default values and accepts user inputs.
    // The constructor gets called and the memeber variables are initialized using an initialization list.
    Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' } //Uniform initializattion.
    {
        // No need for assignment here.
        // m_value = 1 ; // This is assignment, not initialization.
    }
    void print()
    {
        std:: cout << "(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n" ;
    }
};

void ex0(){
    Something something{} ; // Create an instance of the Something class type and initialize to its default values.
    something.print() ; // acess the member function print() belonging to the something object.
}


int main()
{
    ex0() ;
    //ex1() ;

    return 0 ;
}
