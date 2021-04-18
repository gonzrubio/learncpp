/*
When instantiating a function template for a given type, the compiler stencils out a copy of
the templated function and replaces the template type parameters with the actual types used in
the variable declaration. This means a particular function will have the same implementation
details for each instanced type (just using different types). While most of the time, this is
exactly what you want, occasionally there are cases where it is useful to implement a templated
function slightly different for a specific data type.

Template specialization is one way to accomplish this.
*/

#include <iostream>

template <class T>
class Storage {
private:
    T m_value;
public:
    Storage(T value) {
        m_value = value;
    }
    ~Storage() { }
    void print() {
        std::cout << m_value << '\n';
    }
};

template <>
void Storage<double>::print() {
    std::cout << std::scientific << m_value << '\n';
}

template <>
Storage<char*>::Storage(char* value) {
    // Figure out how long the string in value is
    int length = 0;
    while (value[length] != '\0')
        ++length;
    ++length; // +1 to account for null terminator

    // Allocate memory to hold the value string
    m_value = new char[length];

    // Copy the actual value string into the m_value memory we just allocated
    for (int count = 0; count < length; ++count)
        m_value[count] = value[count];
}

template <>
Storage<char*>::~Storage() {
    delete[] m_value;
}

int main() {
    // Define some storage units
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    // Print out some values
    nValue.print();
    dValue.print();

    // Dynamically allocate a temporary string
    char* string = new char[40];

    // Ask user for their name
    std::cout << "Enter your name: ";
    std::cin >> string;

    // Store the name
    Storage<char*> storage(string);

    // Delete the temporary string
    delete[] string;

    // Print out our value
    storage.print(); // This will print garbage
}