#pragma once
#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include "vecpoint.h"

struct Surface
{
	Vector3D v1, v2;
	Surface();
	Surface(const Vector3D& vec1, const Vector3D& vec2);
};

struct Equation
{
	double A, B, C, D;
	Equation();
	Equation(const Surface& s);
};

bool pointInput(Point3D& p);
void swap(double mat[4][4], int row1, int row2, int col);
int rankOfMatrix(double mat[4][4]);
bool isParallel(const Surface& s1, const Surface& s2);

#endif
