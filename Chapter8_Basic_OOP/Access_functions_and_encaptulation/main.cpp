/*
    Encapsulation:
    In OOP, Encapsulation (information hiding) is the process of keeping
    the details of how an object is implemeneted hidden away from the users of the object.
    Encapsulation is implemented with acess specifiers.

    Access functions:
    A short public member function that retrieves or changes the value of a private member variable.
    1) Getter (accessors) are functions that return the value of a private member variable.
    2) Setter (mutator) are functions that set the value of a private member varibale.

    Rule: Getters provide "read-only" acess to data and thus should return by value or const reference.

    Conlusion: Encapsulation allows to use a class without knowing how it is implemented. This reduces
    the level of complexity dramatically and makes programs more mainatinable.
*/

#include <iostream>

class String
{
    // My implementation of String type
private:
    // These variables have an intrinsic invariant connection. That is why they are private.
    char *m_str ;      // We will dynamically allocate our string here.
    int m_len{ 0 } ;   // Keep track of the string length.
public:
    int getLength()
    {
        // Access function to get the value of a private member (Getter/accessor).
        return (m_len) ;
    }
    // No setter provided for m_len because we dont want the user to set the length directly.
};

class Date
{
private:
    int m_month;
    int m_day;
    int m_year;

public:
    int getMonth() { return m_month; } // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    int getDay() { return m_day; } // getter for day
    void setDay(int day) { m_day = day; } // setter for day

    int getYear() { return m_year; } // getter for year
    void setYear(int year) { m_year = year; } // setter for year
};

int main()
{
    String str ;
    std::cout << str.getLength() << "\n" ;

    return 0;
}
