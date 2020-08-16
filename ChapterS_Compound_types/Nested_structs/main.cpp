#include <iostream>

using namespace std;

struct Person
{
    // User defined variable of type Person (which is a struct).
    string name ;
    int age ;
    string gender ;
};

struct Marriage
{
    // Nested struct. Variable type is Marriage
    Person a ;
    Person b ;
    int yearsMarried ;
    int peopleAttended ;
};

void personInfo(const Person &p)
{
    cout << "The person name is: " << p.name << endl ;
    cout << "The person gender is: " << p.gender << endl ;
    cout << "The person age is: " << p.age << endl << endl ;
}

void marriageInfo(Marriage &m)
{
    cout << m.a.name << " is married to " << m.b.name << "." << endl ;
    cout << "They have been married for " << m.yearsMarried << " years." << endl ;
    cout << m.peopleAttended << " people attended their wedding." << endl << endl ;
}

int main()
{
    Person Gonzalo{"Gonzalo", 25, "Male"} ;
    Person Emma{"Emma",28,"Female"} ;

    personInfo(Gonzalo) ;

    Marriage marriage{Gonzalo,Emma,69,420} ;

    marriageInfo(marriage) ;

    return 0;
}
