#include <iostream>
#include <string>

using namespace std ;

class DateClass
{
public:
    int m_day ;
    int m_month ;
    int m_year ;

    void print()
    {
        cout << "The date is " << m_day << "/" << m_month << "/" << m_year << "." << endl ;
    }

} ;

class Employee
{
public:
    string m_name ;
    int m_id ;
    double m_wage ;

    void print()
    {
        cout << endl << "Name: " << m_name << endl ;
        cout << "Id: " << m_id << endl ;
        cout << "Wage: $" << m_wage << endl ;
    }

} ;

int main()
{
    // Tip: When debugging use cerr instead of cout.
    // cerr does not buffer.
    // Also omit indentation to identify that it was ment for debugging.
cerr << "main() was called." << endl ;


    DateClass today{16,03,2020} ;

    // Call the print() member function (method) associated with the today object of type DateClass.
    today.print() ;

    // Dcelare two employess.
    Employee Joe{"Joe", 1, 25.00} ;
    Employee Jen{"Jen", 2, 22.25} ;

    // Print out the employess info.
    Joe.print() ;
    Jen.print() ;

    return 0 ;
}
