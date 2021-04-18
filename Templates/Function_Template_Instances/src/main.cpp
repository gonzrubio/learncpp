/*
Function templates are functions that serve as a pattern for creating other similar functions.
The basic idea behind function templates is to create a function without having to specify the
exact type(s) of some or all of the variables. Instead, we define the function using placeholder types,
called template type parameters.

The function with actual types is called a function template instance.
*/

#include <iostream>
#include <string>

class Cents {
private:
    int m_cents;
public:
    Cents(int cents) : m_cents{ cents } {}
    friend bool operator>(const Cents& c1, const Cents& c2) {
        return (c1.m_cents > c2.m_cents);
    }
    friend std::ostream& operator<< (std::ostream& out, const Cents& cents) {
        out << cents.m_cents << " cents ";
        return out;
    }
    Cents& operator+=(const Cents& cents) {
        m_cents += cents.m_cents;
        return *this;
    }
    Cents& operator/=(int value) {
        m_cents /= value;
        return *this;
    }
};

template <typename T> // this is the template parameter declaration
const T& max(const T& x, const T& y) {
    return (x > y) ? x : y;
}

template <typename T>
T average(const T* array, int length) {
    T ave{ 0 };
    for (int index{ 0 }; index < length; index++) {
        ave += array[index];
    }
    ave /= length;
    return ave;
}

int main() {
    Cents c1{ 17 };
    Cents c2{ 16 };
    std::cout << (c1 > c2) << std::endl;

    int array1[]{ 5, 3, 2, 1, 4 };
    std::cout << average(array1, 5) << '\n';

    double array2[]{ 3.12, 3.45, 9.23, 6.34 };
    std::cout << average(array2, 4) << '\n';

    Cents array3[]{ Cents(5), Cents(10), Cents(15), Cents(14) };
    std::cout << average(array3, 4) << '\n';
}