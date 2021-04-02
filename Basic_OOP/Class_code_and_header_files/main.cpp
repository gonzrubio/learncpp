#include <iostream> 

/* Defining member fucntions outside the class definition */
// Using an already -written class only requires understanding of the public interface (the public member functions).
// So it is useful to separete the declaration and implementation portions, this is achieved by defining the class member functions
// outside of the class definition.

class Date
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Date(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay() { return m_day; }
};

// Date constructor
Date::Date(int year, int month, int day)
{
    SetDate(year, month, day);
}

// Date member function
void Date::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

/* Putting class definitions in a header file */
// Class definitions can be put in header files to be reused in multiple files or projects. 
// Typically, the class definition is put in a header file of the same name as the class, and the member
// functions defined outside the class are put in a .cpp file with the smae name as the class.
// Default parameters for member functions should be declared in the class definition (in the header file),
// where they can be seen by whomever #includes the header.

int main()
{
    std::cout << "Hello World!\n";
    return 0;
}
