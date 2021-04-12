/*
A dependency occurs when one object invokes another object’s functionality in order to accomplish some specific task.
A dependency is always a unidirectional relationship. 

Dependencies typically are not represented at the class level -- that is, the object being depended on is not linked
as a member. Rather, the object being depended on is typically instantiated as needed,
or passed into a function as a parameter.
*/

#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

    return out;
}

int main()
{
    Point point1(2.0, 3.0, 4.0);

    std::cout << point1;

    return 0;
}