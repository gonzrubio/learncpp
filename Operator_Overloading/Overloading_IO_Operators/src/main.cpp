/*
Overloading operator<< is similar to overloading operator+ (they are both binary operators), except that the parameter
types are different. The left operand is the std::cout object (std::cout is actually an object of type std::ostream),
and the right operand is your custom data type object.
*/

#include <iostream>

class Point {
private:
    double m_x;
    double m_y;
    double m_z;
public:
    Point(double x=0.0, double y=0.0, double z=0.0) : m_x{ x }, m_y{ y }, m_z{ z } {}
    friend std::ostream& operator<<(std::ostream& out, const Point point);
};

std::ostream& operator<<(std::ostream &out, const Point point) {
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
    return out;
}


int main() {
    Point point1{ 1.0, 2.0, 3.0 };
    std::cout << point1 << std::endl;
    
}