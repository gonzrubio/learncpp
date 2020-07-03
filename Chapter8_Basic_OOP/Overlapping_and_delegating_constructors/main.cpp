#include <iostream>
#include <string>

class Foo
{
public:
    Foo()
    {
        Init();
    }

    Foo(int value)
    {
        Init();
        // do something with value
    }

    void Init()
    {
        // code to init Foo
    }
};

class Goo
{
private:

public:
    Goo()
    {
        // code to do A
    }
    /// Make sure you’re calling the constructor from the member initializer list, not in the body of the constructor.
    Goo(int value): Goo() // use Goo() default constructor to do A
    {
        // code to do B
    }

};

class Employee
{
private:
    int m_id;
    std::string m_name;

public:
    Employee(int id=0, const std::string &name=""):
        m_id(id), m_name(name)
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a delegating constructor to minimize redundant code
    Employee(const std::string &name) : Employee(0, name) { }
};

int main()
{
    // It is fairly common to include an Init() function that initializes member
    // variables to their default values, and then have each constructor call that Init()
    // function before doing its parameter-specific tasks.

    // So your constructors can delegate or initialize, but not both.

    return 0;
}
