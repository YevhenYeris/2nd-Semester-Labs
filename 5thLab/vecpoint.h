#pragma once
#ifndef VECPOINT_H
#define VECPOINT_H

#include <cmath>
#include <iostream>
class Vector3D;
struct Point3D;

struct Point3D
	//Точка у 3Д просторі
{
	double x, y, z;
};

class Vector3D {
	//Вектор у 3Д просторі
public:
	Vector3D();
	~Vector3D();
	Vector3D(double a1, double b1, double c1);
	Vector3D(const Vector3D& a);
	Vector3D(Point3D s, Point3D f);
	Vector3D(Vector2D v, char axis);

	Vector3D right();
	Vector3D up();
	Vector3D left();
	Vector3D down();
	Vector3D forward();
	Vector3D back();
	Vector3D zero();
	void rotate(char axis, double n);
	void normalize();
	int cmp(Vector3D v1, Vector3D v2);
	void str();
	double length();
	void setCoord(double x, double y, double z);
	double getA();
	double getB();
	double getC();
	Vector2D to2D(char axis);

	Vector3D operator + (const Vector3D& v) const;
	Vector3D operator - (const Vector3D& v) const;
	bool operator == (const Vector3D& v) const;
	Vector3D operator * (const double s) const;
	Vector3D operator / (const double s) const;

	void mirror();
	double scalar_mult(Vector3D v1, Vector3D v2);
	double angle(Vector3D v1, Vector3D v2);
	void cross_product(Vector3D v1, Vector3D v2);

private:
	double a, b, c;
	Point3D s, f;
};
#endif