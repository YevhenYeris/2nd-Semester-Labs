#include "vectors.h"

//����������� �����������
Vector2D::Vector2D() : a(0), b(0), s({ 0, 0 }), f({ a, b })
{
}

//����������� �� 2 ������������
Vector2D::Vector2D(double a1, double b1) : a(a1), b(b1), s({ 0, 0 }), f({ a1, b1 })
{
}

//����������� ����������
Vector2D::~Vector2D()
{
}

//����������� ��ﳿ
Vector2D::Vector2D(const Vector2D& a) : a(a.a), b(a.b), s({ 0, 0 }), f({ a.a, a.b })
{
}

//���������� �� ����� �������
Vector2D::Vector2D(Point2D a, Point2D b) : a(b.x - a.x), b(b.y - a.y), s(a), f(b)
{
}

//����������� �� 3� �������� � ��������
Vector2D::Vector2D(Vector3D v, char axis) : a(0), b(0), s({ 0, 0 }), f({ 0, 0 })
{
	switch (axis)
	{
	case 'x': a = v.getB(); b = v.getC();
		break;
	case 'y': a = v.getA(); b = v.getC();
		break;
	case 'z': a = v.getA(); b = v.getB();
		break;
	}
}

//�������� ������ (1, 0)
Vector2D Vector2D::right()
{
	return Vector2D{ 1, 0 };
}

//�������� ������ (0, 1)
Vector2D Vector2D::up()
{
	return Vector2D{ 0, 1 };
}

//�������� ������ (-1, 0)
Vector2D Vector2D::left()
{
	return Vector2D{ -1, 0 };
}

//�������� ������ (0, -1)
Vector2D Vector2D::down()
{
	return Vector2D{ 0, -1 };
}

//�������� ������ (0, 0)
Vector2D Vector2D::zero()
{
	return Vector2D{ 0, 0 };
}

//������� ������� �� ��� n 
void Vector2D::rotate(double n)
{
	double a1, b1;
	a1 = a * cos(n) - b * sin(n);
	b1 = a * sin(n) + b * cos(n);
	this->a = a1;
	this->b = b1;
}

//������������ ������
void Vector2D::normalize()
{
	double len = this->length();
	this->a /= len;
	this->b /= len;
}

//�������� ��� �������
int Vector2D::cmp(Vector2D v1, Vector2D v2)
{
	if (v1.a == v2.a && v2.b == v2.b)
		return 0;
	else return (v1.length() - v2.length());
}

//������� ������
void Vector2D::str()
{
	std::cout << "vector(" << a << ", " << b << ")\n";
}

//������ ��������� �������
void Vector2D::setCoord(double x, double y)
{
	this->a = x;
	this->b = y;
}

//������ ����� �
double Vector2D::getA()
{
	return this->a;
}

//������ ����� �
double Vector2D::getB()
{
	return this->b;
}

//������������ � 3� ������
Vector3D Vector2D::to3D(char axis)
{
	switch (axis)
	{
	case 'x': return Vector3D{ 0, a, b};
			break;
	case 'y': return Vector3D{ a, 0, b };
			break;
	case 'z': return Vector3D{ a, b, 0 };
			break;
	default: return Vector3D();
	}
}

//���������� �����������
void Vector2D::mirror()
{
	a *= -1;
	b *= -1;
}

//��������� �������
double Vector2D::scalar_mult(Vector2D v1, Vector2D v2)
{
	return (v1.a * v2.a + v1.b * v2.b);
}

//�������� ��� �� ����� ���������
double Vector2D::angle(Vector2D v1, Vector2D v2)
{
	return (scalar_mult(v1, v2)) / v1.length() * v2.length();
}

//�������� ������� �������
double Vector2D::length()
{
	return (sqrt(pow(a, 2) + pow(b, 2)));
}

Vector2D Vector2D::operator + (const Vector2D& v) const
{
	return Vector2D{ a + v.a, b + v.b };
}

Vector2D Vector2D::operator - (const Vector2D& v) const
{
	return Vector2D{ a - v.a, b - v.b };
}

bool Vector2D::operator == (const Vector2D& v) const
{
	if (a == v.a && b == v.b)
		return 1;
	else return 0;
}

Vector2D Vector2D::operator * (const double s) const
{
	return Vector2D{ a * s, b * s };
}

Vector2D Vector2D::operator / (const double s) const
{
	return Vector2D{ a / s, b / s };
}
/*




*/

//����������� �����������
Vector3D::Vector3D() :a(0), b(0), c(0), s({ 0, 0, 0 }), f({ 0, 0, 0 })
{
}

//����������� �� ������ ������������
Vector3D::Vector3D(double a1, double b1, double c1) : a(a1), b(b1), c(c1), s({ 0, 0, 0 }), f({ a1, b1, c1 })
{
}

//����������� ����������
Vector3D::~Vector3D()
{
}

//����������� ��ﳿ
Vector3D::Vector3D(const Vector3D& a) :a(a.a), b(a.b), c(a.c), s({ 0, 0, 0 }), f({ a.a, a.b, a.c })
{
}

//����������� �� ����� �������
Vector3D::Vector3D(Point3D a, Point3D b) : a(b.x - a.x), b(b.y - a.y), c(b.z - a.z), s(a), f(b)
{
}

//����������� �� ��������� 2� ��������
Vector3D::Vector3D(Vector2D v, char axis) : a(0), b(0), c(0), s({ 0, 0 }), f({ 0, 0 })
{
	switch (axis)
	{
	case 'x': b = v.getB(); c = v.getB();
		break;
	case 'y': a = v.getA(); c = v.getB();
		break;
	case 'z': a = v.getA(); b = v.getB();
		break;
	}
}

//�������� ������ (1, 0, 0)
Vector3D Vector3D::right()
{
	return Vector3D{ 1, 0, 0 };
}

//�������� ������ (0, 0, 1)
Vector3D Vector3D::up()
{
	return Vector3D{ 0, 0, 1 };
}

//�������� ������ (-1, 0, 0)
Vector3D Vector3D::left()
{
	return Vector3D{ -1, 0, 0 };
}

//�������� ������ (0, 0, -1)
Vector3D Vector3D::down()
{
	return Vector3D{ 0, 0, -1 };
}

//�������� ������ (0, 1, 0)
Vector3D Vector3D::forward()
{
	return Vector3D{ 0, 1, 0 };
}

//�������� ������ (0, -1, 0)
Vector3D Vector3D::back()
{
	return Vector3D{ 0, -1, 0 };
}

//�������� ������ (0, 0, 0)
Vector3D Vector3D::zero()
{
	return Vector3D{ 0, 0, 0 };
}

//������� ������ �a ��� n ������� �� axis
void Vector3D::rotate(char axis, double n)
{
	double a1(0), b1(0), c1(0);
	switch (axis)
	{
	case 'x': b1 = b * cos(n) - c * sin(n); c1 = b * sin(n) + c * cos(n);
		break;
	case 'y': a1 = a * cos(n) + c * sin(n); c1 = -a * sin(n) + c * cos(n);
		break;
	case 'z':  a1 = a * cos(n) - b * sin(n); b1 = a * sin(n) * b * cos(n);
	}
	this->a = a1;
	this->b = b1;
	this->c = c1;
}

//������������ ������
void Vector3D::normalize()
{
	double len(0);
	len = this->length();
	this->a /= len;
	this->b /= len;
	this->c /= len;
}

//�������� ��� �������
int Vector3D::cmp(Vector3D v1, Vector3D v2)
{
	if (v1.a == v2.a && v1.b == v2.b && v1.c == v2.c)
		return 0;
	else return (v1.length() - v2.length());
}

//������� ������ �� �����
void Vector3D::str()
{
	std::cout << "\n vector(" << a << ", " << b << ", " << c << ")\n";
}

//������ ���������
void Vector3D::setCoord(double x, double y, double z)
{
	this->a = x;
	this->b = y;
	this->c = z;
}

//�������� ���������� �
double Vector3D::getA()
{
	return this->a;
}

//�������� ���������� �
double Vector3D::getB()
{
	return this->b;
}

//�������� ���������� �
double Vector3D::getC()
{
	return this->c;
}

//����������� ������� � 2� �������� �� axis
Vector2D Vector3D::to2D(char axis)
{
	switch (axis)
	{
	case 'x': return Vector2D{ b, c };
			break;
	case 'y': return Vector2D{ a, c };
			break;
	case 'z': return Vector2D{ a, b };
			break;
	default: return Vector2D();
	}
}

//���������� ����������� �������
void Vector3D::mirror()
{
	a *= -1;
	b *= -1;
	c *= -1;
}

//��������� �������
double Vector3D::scalar_mult(Vector3D v1, Vector3D v2)
{
	return (v1.a * v2.a + v1.b * v2.b * v1.c * v2.c);
}

//�������� ��� �� ���������
double Vector3D::angle(Vector3D v1, Vector3D v2)
{
	return (scalar_mult(v1, v2) / v1.length() * v2.length());
}

//��������� �������
void Vector3D::cross_product(Vector3D v1, Vector3D v2)
{
	double matrix[2][3] = { v1.a, v1.b, v1.c, v2.a, v2.b, v2.c };
	a = v1.b * v2.c - v1.c * v2.b;
	b = v1.a * v2.c - v1.c * v2.a;
	c = v1.a * v2.b - v1.b * v2.a;
}

//�������� ������� ������
double Vector3D::length()
{
	return (sqrt(pow(a, 2) * pow(b, 2) * pow(c, 2)));
}

Vector3D Vector3D::operator + (const Vector3D& v) const
{
	return Vector3D{ a + v.a, b + v.b, c + v.c };
}

Vector3D Vector3D::operator - (const Vector3D& v) const
{
	return Vector3D{ a - v.a, b - v.b, c - v.c };
}

bool Vector3D::operator == (const Vector3D& v) const
{
	if (a == v.a && b == v.b && c == v.c)
		return 1;
	else return 0;
}

Vector3D Vector3D::operator * (const double s) const
{
	return Vector3D{ a * s, b * s, c * s };
}

Vector3D Vector3D::operator / (const double s) const
{
	return Vector3D{ a / s, b / s, c / s };
}