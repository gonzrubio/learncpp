/* Anonymous objects */
// An anonymous object is a value that has no name. Because they have no name, it is not possible
// to refer to them beyind the point where they are created. They have expression scope, menaning
// that they are created, evaluated and destroyed within a single expression.
// Some examples of anonymous objects are return values and function arguments. For built-in data types.

/* Summary */
// Anonymous objects are used to pass or return built-in types to avois making temporary variables.
// Memory allocated dynamically is done anonymoulsy. That is why it is assigned to a pointer, otherwise
// we would have no eay to refer to it.
// Anonymous objects have expression scope therefore they can only be used once.

#include <iostream>

class Cent {
private:
    int m_cents;
public:
    Cent(int cent) { m_cents = cent; }
    // const since it does not modify the state of the object and allows pass-by-address.
    int getCents() const { return m_cents; }
};

// Function to add two cent objects
Cent add(const Cent& c1, const Cent& c2) {
    return c1.getCents() + c2.getCents();
}

int main()
{
    // add and print the value of two cent objects.
    std::cout << add(Cent{ 60 }, Cent{ 9 }).getCents() << std::endl;
}
