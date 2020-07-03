#include <iostream>
#include <vector>

/*
    OOP means that an object is a piece of memory that holds a value and we can
    name that piece of memory using a variable, and it also means that we combine
    properties and behaviours.

    In OOP we want our types to hold data AND provide functions that work with the data.
    Using the class keyword defines a new user-defined type called a class.

    Just like a struct declaration, a class declaration (definition) does not allocate any memory,
    it only defines what the class looks like. Class declarations (definitions) are like
    a blueprint -- they describe what the resulting object will look like, but they do not
    actually create the object. To create an object of that class, a variable of that
    class type must be defined.

    Note: Always use a class for objects that contains data and memeber functions.
    Use data-only structs when using only data.
*/

struct DateStruct
{
    // This declaratin does not allocate any memory, it only defines what the struct looks like.
    int year ;
    int month ;
    int day ;
};

void printDate(const DateStruct &date)
{
    // Pass by const reference since we want read-only
    // and don't want to modify the struct.
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n" ;
}

void ex0()
{
    // Declare and initialize a struct of type DateStruct using uniform initialization.
    DateStruct today{2020, 04, 2} ;
    // Use memeber selection operator (.) to change one of the memebers in the struct.
    today.day = 1 ;
    printDate(today) ;
}

class DateClass
{
    // This declaration does not allocate memory. It showas what the resulting object looks like.
    // "m_" prefix for memeber variables helps distinguish from function parameters or local variables.
    // Class names begin with an upper-case letter.
public:
    int m_year ;
    int m_month ;
    int m_day ;

    // Functions defined inside classes (and structs) are called memeber functions (methods).
    void printDate()
    {
        std::cout << m_day << "/" << m_month << "/" << m_year ;
    }
};

void ex1()
{
    // Declare and initialize a variable of class DateClass.
    DateClass today{2002,04,01} ;

    // Use member selection operator to call a member function of the class.
    // Because today is an object, it can hold data and has properties
    // and behavoiurs associated with it.
    // Memeber function calls are associated with an object of the class.
    // Tell the compiler to call th printDate member fucntion associated
    // with the today object.
    today.printDate() ;

}

class Calculator
{
    // This calculator can add (behaviour) and remeber past calls (properties).
public:
    // This is a nested type alias. "number_t" where _t means type.
    using number_t = int ;

    // Dynamic vector where the elements are of type number_type.
    std::vector<number_t> m_resultHistory{} ;

    // Member function with return type number_t (nested alias).
    number_t add(number_t a, number_t b)
    {
        // Type is auto because type could change in the future.
        //auto result{a + b} ;
        //m_resultHistory.push_back(result) ;
        m_resultHistory.push_back(a + b) ;
        return (a + b) ;
    }
};


void ex2()
{
    // Classes can have memeber types or nested types (including type aliases).
    // In this example we create a calculator where we can change the type
    // of number it is using if we ever need to.

    // Instantiate and initialize a Calculator class object.
    Calculator calculator{} ;
    std::cout << calculator.add(3, 4) << '\n' ; // 7
    std::cout << calculator.add(99, 24) << '\n' ; // 123

    for (result : calculator.m_resultHistory)
        std::cout << result << " "  ;

}

class IntPair
{
public:
    // Nested type alias.
    using number_t = int ;
    // memeber variables.
    number_t m_a ;
    number_t m_b ;
    // Member functions.
    void sett(int first, int second)
    {
        m_a = first ;
        m_b = second ;
    }
    void printter()
    {
        std::cout << "first = " << m_a << "\n" ;
        std::cout << "second = " << m_b << "\n" ;
    }

};

void ex3()
{
    // Create a class called IntPair that holds two integers.
    // create member function named “set” that will let you assign values to the integers.
    // one named “print” that will print the values of the variables.

    IntPair p1 ;
    p1.sett(1,1) ;

    IntPair p2 ;
    p2.sett(2,2) ;

    p1.printter() ;
    p2.printter() ;

}

int main()
{
    // ex0() ;
    // ex1() ;
    // ex2() ;
    ex3() ;

    return 0;
}
