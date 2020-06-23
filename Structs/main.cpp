#include <iostream>

using namespace std;

struct Advertising
{
   int shown ; // Number of ads shown to readers.
   double perc ; // Percentage of ads clicked on by users.
   double aveEarn ;// How much was earned on average for each ad that was clicked.
} ;

struct Person
{
    // This is a structure variable of type Person.
    string name ;
    int age ;
    string gender ;

};

void dayProfit(Advertising website)
{
    cout << "There were " << website.shown << " number of ads shown." << endl ;
    cout << website.perc << " percent of the ads were clicked on by users." << endl ;
    cout << "$" <<website.aveEarn << " were earned on average for each ad that was clicked." << endl ;
    double temp = website.perc/100 ;
    double profit = website.shown * temp * website.aveEarn ;
    cout << "The website made $" << profit << " that day." << endl ;
}

Advertising getInfo()
{
    Advertising temp ;
    cout << "Number of ads shown: " ;
    cin >> temp.shown ;

    cout << "Percentage of ads clicked on by users: " ;
    cin >> temp.perc ;

    cout << "How much was earned on average for each ad that was clicked: " ;
    cin >> temp.aveEarn ;

    return temp ;
}

// Declare a struct and its identifier.
struct Fraction
{
    // Define the fields and member of the structure.
    int numerator ;
    int denominator ;

};

// Note: the return type of getFraction() is 'Fraction', which in turn is of struct type.
Fraction getFraction()
{
    // No variable is neither passed-by-value nor passed-by-reference.
    // Need to create a struct variable to hold the user inputs.
    // This variable exist inside the scope of this function and the user input
    // is returned in pass-by-value.

    Fraction userInput ;
    cout << "Enter an integer for the numerator: " ;
    cin >> userInput.numerator ;
    cout << "Enter an integer for the denominator: " ;
    cin >> userInput.denominator ;
    cout << endl ;

    return userInput ;
}

// Note: the type of the inputs are Fractions (struct).
void multiply(Fraction a,Fraction b)
{
    //double top{a.numerator * b.numerator} ;
    //double bottom{a.denominator * b.denominator} ;
    cout << "Their product is: " << static_cast<double> (a.numerator * b.numerator)/(a.denominator * b.denominator) << endl << endl ;
    // cout << "Their product is: " << top << "/" << bottom << "."endl ;
    //cout << "Their product is: " << product << "." << endl ;
}

void printPersonInfo(const Person &p)
{
    // We pass the variable by reference to avoid expensive copy.
    // It is a constant refernce since we want read only.
    cout << "The name of the person is: " << p.name << endl ;
    cout << "The age of the person is: " << p.age << endl ;
    cout << "The gender of the person is: " << p.gender << endl << endl ;
}

int main()
{

    /*
    2 ) Pass the advertising struct to a function that prints each of the values,
    and then calculates how much you made for that day (multiply all 3 fields together).
    */

    // Advertising website = getInfo() ;
    // dayProfit(website) ;

    /*
    Create a struct to hold a fraction. The struct should have an integer numerator and an integer denominator member.
    Declare 2 fraction variables and read them in from the user.
    Write a function 'multiply' that takes both fractions, multiplies them together, & prints the result out as a decimal.
    */

    // Declare two fraction variables of type struct. The fields are inputs from the user.
    // The function return-type of getFraction() is Fraction, which itself is a struct.
    Fraction fraction1 = getFraction() ;
    Fraction fraction2 = getFraction() ;
    multiply(fraction1,fraction2) ;

    Person Gonzalo{"Gonzalo",25,"Male"} ;
    Person Emma{"Emma",29,"Female"} ;
    printPersonInfo(Gonzalo) ;

    // Create a an array that holds variables of type Person and print the second person info.
    Person people[]{Gonzalo,Emma} ;
    printPersonInfo(people[1]) ;

    return 0;
}
