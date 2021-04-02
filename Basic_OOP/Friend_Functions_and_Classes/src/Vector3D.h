#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3D.h" // for declaring Point3D::moveByVector() as a friend

class Vector3D {
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Vector3D(const double x = 0, const double y = 0, const double z = 0);
	void print() const;
	friend void Point3D::moveByVector(const Vector3D& v);
};

#endif // 



