#include <iostream>

/*
    When writing a class with multiple constructors, having to specify default
    values in all constructors results in redundant code. If we update the
    value of a member, we need tro update evry constructor.

    Rule: Favour use of non-static member initialization to give default values for memeber variables.
*/

class Rectangle
{
private:
    // GIve normal class members a default initialization value directly.
    double m_width{1.1} ;  // m_width has a default value of 1.0
    double m_length{1.1} ; // m_length has a default value of 1.0
public:
    Rectangle()
    {
        // Default constructor.
    }
    Rectangle(double width)
        : m_width{width}
    {
    }
    Rectangle(double width, double length)
        : m_width{width}, m_length{length}
    {
    }
    void print()
    {
        std::cout << "width = " << m_width << ", length = " << m_length << "\n" ;
    }
};

void ex0()
{
    Rectangle first{ } ;      // Default.
    first.print() ;
    Rectangle second{2.2} ;
    second.print() ;
    Rectangle third{3.3,4.4} ;
    third.print() ;
}

class Ball
{
private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 } ;

public:
        // Default constructor with no parameters
	Ball()
	{
		//m_color = "black";
		//m_radius = 10.0;
	}
        // Constructor with only color parameter (radius will use default value)
	Ball(const std::string &color) : m_color{ color }
	{
		//m_color = color;
		//m_radius = 10.0;
	}
        // Constructor with only radius parameter (color will use default value)
	Ball(double radius) : m_radius{ radius }
	{
		//m_color = "black";
		//m_radius = radius;
	}

        // Constructor with both color and radius parameters
	Ball(const std::string &color, double radius) : m_color{ color }, m_radius{ radius }
	{
		//m_color = color;
		//m_radius = radius;
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

void ex1()
{
    // Update the following program to use non-static member initialization and member initializer lists.
	Ball def ;
	def.print() ;

	Ball blue{ "blue" } ;
	blue.print() ;

	Ball twenty{ 20.0 } ;
	twenty.print() ;

	Ball blueTwenty{ "blue", 20.0 } ;
	blueTwenty.print() ;
}

void ex2()
{
    // Why do we need to declare an empty default constructor in the program above,
    // since all members are initialized via non-static member initialization?

    // A: Becauseif we provide non-default constructors the compiler wont make a default one for us
    // and will produce a compile error if we instantiate an object with no parameters.
}

int main()
{
    //ex0() ;
    //ex1() ;
    ex2() ;

    return 0;
}
