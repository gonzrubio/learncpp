#pragma once
#ifndef POINT3D_H
#define POINT3D_H

class Vector3D; // forward declaration for class Vector3D for function moveByVector()

class Point3D {
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Point3D(const double x = 0, const double y = 0, const double z = 0);
	void print() const;
	void moveByVector(const Vector3D &v); // forward declaration above needed for this line
};

#endif
