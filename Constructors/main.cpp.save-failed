#include <iostream>
#include <cassert>
#include <string>

/*
    We can initialize private mebers of a class using constructors.
    A constructor is a member function that is automatically called when
    an objetc of that class is instantiated.

    1) Constructors must have the same name as the class (with the same capitalization).
    2) Constructors have no return type (not even void).

    Rule: If you have constructors in your class and need a constructor that does nothing
    use = default.

    Constructors serve two purposes:
    1) They determine who can create an object. An object of a class can only be created
    if a matching constructor can be found.
    2) Constructors can be used ot initialize objects.
    Rule: Always initialize all member variables in your objects.
*/

class Fraction
{
private:
    int m_numerator ;
    int m_denominator ;
public:
    /*Fraction() // Redundant
    {
        // Default constructor - No arguments and no return type.
        // Automatically called when an object of the Fraction class is instantiated.
        // Without a default constructor the private memebers would have garbage numbers.
        m_numerator = 0 ;
        m_denominator = 1 ;
    }*/
    Fraction(int numerator=0, int denominator = 1)
    {
        // This constructor allows for direct and uniform initialization.
        // Both constructors can coexist due to function overloading so as long
        // as they have unique parameters.
        assert(denominator != 0 && "Denominator can not be zero.") ;
        m_numerator = numerator ;
        m_denominator = denominator ;
    }
    int getNumerator(){ return m_numerator ; }
    int getDenominator(){ return m_denominator ; }
    double getValue(){ return static_cast<double>(m_numerator) / m_denominator ; }
};

void ex0()
{
    // Because we are instantiating a Fraction object with no arguments,
    // the default constructor Fraction() is called immediatly after memory
    // is allocated for the object, and our object will be initialized.
    Fraction frac ;
    std::cout << frac.getNumerator() << "/" << frac.getDenominator() << "\n" ;

    Fraction threeQuarters {3,4} ;
    std::cout << threeQuarters.getNumerator() << "/" << threeQuarters.getDenominator() << "\n" ;

    // Uses the default value for denominator.
    Fraction six{ 6 } ;
    std::cout << six.getNumerator() << "/" << six.getDenominator() << "\n" ;

    //Fraction notPossible{1,0} ;
    //std::cout << notPossible.getNumerator() << "/" << notPossible.getDenominator() << "\n" ;

}

class A
{
public:
    // Default constructor for class A.
    A(){ std::cout << "A\n" ; }
};

class B
{
private:
    // B contains m_a as a member variable, and it is of type A.
    // This variable must be initialized first since the constructor might need it.
    // In other words, this member variable will have its default constructor called.
    // That happens before the body of the constructor for B executes.
    A m_a ;
public:
    B(){ std::cout << "B \n" ;}
} ;

void ex1()
{
    // A class may contain other classes as variables. By default, when the outer
    // class is constructed, the meber variables will have their default constructors called.
    // This happens before the body of the constructor executes.
    B b ;

    // When variable b is constructed, the B() constructor is called. Bofore the body of
    // the constructor is executed, m_a is initialized, calling the class A default constructor.
    // This prints "A", the the control reutrns to the B() constructor, and the body of B() executes.
}

class Ball
{
private:
    std::string m_color{ } ;
    double m_radius{  } ;
// Ball should provide constructors to set only m_color, set only m_radius, set both, or set neither value.
public:
    // Constructor with no parameters
    Ball()
    {
        m_color = "Black" ;
        m_radius = 10.0 ;
    }
    // Constructor with only color parameter, radius will use the default.
    Ball(const std::string &color)
    {
        m_color = color ;
        m_radius = 10.0 ;
    } ;
    // Constructor with only radius parameter, color will use the default.
    Ball(double radius)
    {
        m_radius = radius ;
        m_color = "Black" ;
    }
    // Constructor with both parameters
    Ball(const std::string &color, double radius)
    {
        m_radius = radius ;
        m_color = color ;
    }
    void print()
    {
        std::cout << "Color: " << m_color << ", Radius: " << m_radius << "\n" ;
    }
};

void ex2()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
}

int main()
{
    ex0() ;
    ex1() ;
    ex2() ;

    // Note: If we dont declare a default constructor, the compiler will create an empty default public constructor
    // This means the object will be instantiable with no parameters. If you have defined other constructors
    // (default or otherwise), the comiler will not create a default constructor for you.

    return 0;
}
