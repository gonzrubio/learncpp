#pragma once
#ifndef POINT2D_H
#define POINT2D_H

class Point2d {
private:
    double m_x;
    double m_y;
public:
    Point2d(const double x = 0.0, const double y = 0) : m_x{ x }, m_y{ y } {}
    void print();
    friend double distanceFrom(const Point2d& p1, const Point2d& p2);
};

#endif // !POINT2D_H


