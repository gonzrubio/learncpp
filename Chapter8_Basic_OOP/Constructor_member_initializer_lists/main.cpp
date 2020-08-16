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

    Summary: Member initializer lists allows us to initialize member variables rather than assign to them.
    This is the only way to initialize members that require values upon initialization.
*/

class Something // Custom data type.
{
private:
    int m_value1 ;
    double m_value2 ;
    char m_value3 ;
    const int m_value4 ;
public:
    // Constructor has default values and allows caller to pass in the initialization values.
    // The constructor gets called and the memeber variables are initialized using an initialization list.
    Something(int m_value1 = 1, double m_value2 = 2.2, char m_value3 = 'c', const int m_value4 = 69)
        : m_value1{ m_value1 }, m_value2{ m_value2 }, m_value3{ m_value3 }, m_value4{m_value4} //Uniform initializattion.
    {
        // No need for assignment here.
        // m_value = 1 ; // This is assignment, not initialization.
    }
    void print()
    {
        std::cout << "(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ", " << m_value4 << ")\n" ;
    }
};

void ex0(){
    Something something{} ; // Create an instance of the Something class type and initialize to its default values.
    something.print() ; // acess the member function print() belonging to the something object.
    Something something2{2,3.3,'d'} ; // Create an instance of the Something class type and initialize to its default values.
    something2.print() ; // acess the member function print() belonging to the something object.
    // Recall... we can only initialize const variables, not assign them.
}

class A{
public:
    A(int x){std::cout << "A " << x << '\n' ;}
};

class B{
private:
    A m_a ;
public:
    B(int y):m_a{y-1}{std::cout << "B " << y << '\n' ;}
};

void ex1(){
    B b{5} ;
    // Member initialization lists can also be used to initialize memeber variables that are classes.
    // When variable b (of type Class B) is constructed, before the body of the constructor executes,
    // member variable m_a is initialized calling the A(int) constructor, executing its body.
    // The control returns to the B constructor and its body executes.
}



class RGBA{
public:
    using component_t = std::uint_fast8_t ;
private:
    component_t m_red ;
    component_t m_green ;
    component_t m_blue ;
    component_t m_alpha ;
public:
    RGBA(component_t m_red = 0, component_t m_green = 0, component_t m_blue = 0, component_t m_alpha = 255)
        :  m_red{m_red}, m_green{m_green}, m_blue{m_blue}, m_alpha{m_alpha}
    {
    }
    void print(){
        std::cout << "(" << (int)m_red << ", " << (int)m_green << ", " << (int)m_blue << ", " << (int)m_alpha << ")\n" ;
    }

};

void Q1(){
    // Write a class named RGBA that contains 4 member variables of type std::uint_fast8_t
    // named m_red, m_green, m_blue, and m_alpha (#include cstdint to access type std::uint_fast8_t).
    // Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha.
    // Create a constructor that uses a member initializer list that allows the user to initialize values
    // for m_red, m_blue, m_green, and m_alpha.
    // Include a print() function that outputs the value of the member variables.

	RGBA teal{ 0, 127, 127 } ;
	teal.print() ; // r=0 g=127 b=127 a=255
}

int main()
{
    ex0() ;
    ex1() ;
    Q1() ;

    return 0 ;
}
