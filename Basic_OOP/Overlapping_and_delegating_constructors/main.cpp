/*
When an object is instantiated, its constructor gets called implicitly. Objects
usually have multiple constructors that have overlapping functionality. We try to avoid duplicating code.

Constructors are allowed to call other constructors, this is called "delegating contructors" or
"constructor chaining".

Note: A constructor delegating to another constructor can not do any memeber initialization.
A constructor is either delegating or initializing but not both.

Best practice: Use delegating contructors to avoid duplicating code from constructors with overlapping functionality.

*/

#include <iostream>
#include <string>

class Employee{
    int m_id{} ;
    std::string m_name{} ;
public:
    // Constructor that allows for caller to pass values and initializes with default values.
    Employee(int id=0, const std::string &name="") : m_id{id}, m_name{name}
    {
        std::cout << "Employee: " << m_name << " created.\n" ;
    }
    // Constructor with overlapping functionality with constructor chaining.
    Employee(const std::string &name) : Employee{0,name} {}
};

void ex1(){
    Employee employee{} ;
    Employee employee2{"Emma"} ;
    Employee employee3{69, "Emma"} ;
}

class Foo{
    // Class with member function to re-initialize a class back to default values.
    // Call this member function in the body of the constructor.
public:
    Foo(){
        init() ;
        // Do something.
    }
    Foo(int value){
        init() ;
        // Do something with value.
        std::cout << value << '\n' ;
    }
    void init(){
        // Code to "initialize/reset" Foo.
    }
};

int main(){

    ex1() ;
    Foo foo{} ;

    return 0 ;
}

