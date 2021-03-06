#include <iostream>
#include <array>
#include <cassert>

/*
    Public memebers are memebers of a class or struct that can be accessed
    from outside of the struct or class. Members of a struct are public by default.

    Private memebers are memebers of a class or struct that can only be accessed
    by other memebers of the class. Members of a class are private by default.

    We can make private members public using the public keyword.
    The public/private keyword are acces specifiers and are followed by a semicolon.

    Rule: Make member variables private and memeber functions public unless have a good reason.

    Note: Acess controls work on per-class basis, not a per-object basis.
    This means that when a fucntion has acess to the private members of a class,
    it can acess the private members of any object of that class type that it can see.

    Members of a class are private by default, this means that they can ONLY be accessed by
    other mebers inside the class and can NOT be accessed by members outside the class.

    Structs vs classes:
        - Classes default members to private and structs to public.
        - Structs inherit from other classes publicly and classes inherit privately.

    Conclusion:
    - A public memeber is a member of a class that can be accessed by anyone inside and outside the class.
    - A private member is a member of a class that can only be accessed by other memebers of that class.
    - An access specifier determines who has access to the memebers that follow the specifier.
    - There are three access specifiers: private, public and protected.
*/

class DateClass
{   // member variables are set private by default.
    int m_year ;
    int m_day ;
    int m_month ;

public: // Public members defined below. These can be accessed from outside the class.
    void setDate(int month, int day, int year)
    {
        // setDate can access the private members of the class because it is a member of the class.
        // This means we can indirectly access those private members from outside the class using this memeber function.
        m_year = year ;
        m_day = day ;
        m_month = month ;
    }

    void printDate()
    {
        std::cout << m_month << "/" << m_day << "/" << m_year ;
    }

    void copyFrom(const DateClass &d)
    {
        // Note: The parameter is a const DateClass object passed by reference, by good practice/rule.
        // Acess controls work on a class basis, not per object basis. We can access ALL the private members of ANY
        // object of that class type that it can see - DateClass in this case.
        // This memeber function can acess the private members of any other DateClass object & assigns them to itself.
        // Note: we access those memebers using the memeber acess operator (.).
        m_year = d.m_year ;
        m_day = d.m_day ;
        m_month = d.m_month ;
    }
};

void ex0()
{
    DateClass date ; // Cant initialize directly because those memebers are private.
    // The memeber funcition setDate gives us inderect access to them (public interface).
    date.setDate(2020,01,04) ;
    std::cout << "date: " ;
    date.printDate() ;

    // New object of the same class
    DateClass date_copy ;
    date_copy.copyFrom(date) ; // Pass by reference.
    std::cout << "\ndate_copy: " ;
    date_copy.printDate() ;

    date.setDate(2020,20,04) ;
    std::cout << "\ndate: " ;
    date.printDate() ;
    std::cout << "\ndate_copy: " ;
    date_copy.printDate() ;
}

class Point3d
{
    int m_x, m_y, m_z ;
public:
    void setValues(int x, int y, int z)
    {
        m_x = x ;
        m_y = y ;
        m_z = z ;
    }
    void print()
    {
        std::cout << "\n<" << m_x << ", " << m_y << ", " << m_z << ">\n" ;
    }
    bool isEqual(const Point3d &p)
    {
        // Member function that takes a Point3d object as a parameter.
        // Determines if the points are in the same location.
        // Note: pass by reference always for classes and strcuts and const for read only.
        return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z) ;
    }
};

void Q2()
{
    /// a)
    Point3d point ;             // Instantiate a Point3d object.
    point.setValues(1, 2, 3) ;  // Initialize the private members acessed through the public memeber function.
    point.print() ;             // Print values using the print memeber function.

    /// b)
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
        std::cout << "point1 and point2 are equal\n";
    else
        std::cout << "point1 and point2 are not equal\n";

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
        std::cout << "point1 and point3 are equal\n";
    else
        std::cout << "point1 and point3 are not equal\n";
}

class Stack
{
private:
    using container_type = std::array<int,10> ;

    container_type m_arr ; // A private fixed array of integers of length 10.
    int m_next{0} ;        // This will hold the index of the next free element on the stack.

public:
    void reset()
    {
        // A public member function named reset() that sets the size to 0.
        m_next = 0 ;
    }
    bool push(const int val)
    {
        // pushes a value on the stack.
        // push() should return false if the array is already full, and true otherwise.
        if ( (unsigned)m_next == m_arr.size() ) return false ;
        else
            m_arr[(unsigned)m_next++] = val ; // InserT, then increase index.
            return true ;
    }

    int pop()
    {
        // pops a value off the stack and returns it.
        // If there are no values on the stack, the code should exit via an assert.
        assert (m_next > 0 && "Can not pop empty stack") ;
        return m_arr[(unsigned)--m_next] ; // Decrease index to move to last element, then return.
    }

    void print()
    {
        // A public member function named print() that prints all the values in the stack.
        std::cout << "( " ;
        for (int element{0} ; element < m_next ; element++)
            std::cout << m_arr[(unsigned)element] << " " ;
        std::cout << ")\n" ;
    }
};

void Q3()
{
    Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();
}

int main()
{
    ex0() ;
    Q2() ;
    Q3() ;
    return 0;
}
