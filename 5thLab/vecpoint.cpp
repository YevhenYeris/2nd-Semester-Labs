#include "vecpoint.h"

//Стандартний конструктор
Vector3D::Vector3D() :a(0), b(0), c(0), s({ 0, 0, 0 }), f({ 0, 0, 0 })
{
}

//Конструктор за трьома координатами
Vector3D::Vector3D(double a1, double b1, double c1) : a(a1), b(b1), c(c1), s({ 0, 0, 0 }), f({ a1, b1, c1 })
{
}

//Стандартний деструктор
Vector3D::~Vector3D()
{
}

//Конструктор копії
Vector3D::Vector3D(const Vector3D& a) :a(a.a), b(a.b), c(a.c), s({ 0, 0, 0 }), f({ a.a, a.b, a.c })
{
}

//Конструктор за двома точками
Vector3D::Vector3D(Point3D a, Point3D b) : a(b.x - a.x), b(b.y - a.y), c(b.z - a.z), s(a), f(b)
{
}

//Конструктор за відповідним 2Д вектором
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

//Отримати вектор (1, 0, 0)
Vector3D Vector3D::right()
{
	return Vector3D{ 1, 0, 0 };
}

//Отримати вектор (0, 0, 1)
Vector3D Vector3D::up()
{
	return Vector3D{ 0, 0, 1 };
}

//Отримати вектор (-1, 0, 0)
Vector3D Vector3D::left()
{
	return Vector3D{ -1, 0, 0 };
}

//Отримати вектор (0, 0, -1)
Vector3D Vector3D::down()
{
	return Vector3D{ 0, 0, -1 };
}

//Отримати вектор (0, 1, 0)
Vector3D Vector3D::forward()
{
	return Vector3D{ 0, 1, 0 };
}

//Отримати вектор (0, -1, 0)
Vector3D Vector3D::back()
{
	return Vector3D{ 0, -1, 0 };
}

//Отримати вектор (0, 0, 0)
Vector3D Vector3D::zero()
{
	return Vector3D{ 0, 0, 0 };
}

//Поворот векора нa кут n відносно осі axis
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

//Нормалізувати вектор
void Vector3D::normalize()
{
	double len(0);
	len = this->length();
	this->a /= len;
	this->b /= len;
	this->c /= len;
}

//Порівняти два вектора
int Vector3D::cmp(Vector3D v1, Vector3D v2)
{
	if (v1.a == v2.a && v1.b == v2.b && v1.c == v2.c)
		return 0;
	else return (v1.length() - v2.length());
}

//Вивести вектор на екран
void Vector3D::str()
{
	std::cout << "\n vector(" << a << ", " << b << ", " << c << ")\n";
}

//Сеттер координат
void Vector3D::setCoord(double x, double y, double z)
{
	this->a = x;
	this->b = y;
	this->c = z;
}

//Отримати координату А
double Vector3D::getA()
{
	return this->a;
}

//Отримати координату В
double Vector3D::getB()
{
	return this->b;
}

//Отримати координату С
double Vector3D::getC()
{
	return this->c;
}

//Конвертація вектора у 2Д відповідно осі axis
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

//Дзеркальне відображення вектора
void Vector3D::mirror()
{
	a *= -1;
	b *= -1;
	c *= -1;
}

//Скалярний добуток
double Vector3D::scalar_mult(Vector3D v1, Vector3D v2)
{
	return (v1.a * v2.a + v1.b * v2.b * v1.c * v2.c);
}

//Отримати кут між векторами
double Vector3D::angle(Vector3D v1, Vector3D v2)
{
	return (scalar_mult(v1, v2) / v1.length() * v2.length());
}

//Векторний добуток
void Vector3D::cross_product(Vector3D v1, Vector3D v2)
{
	double matrix[2][3] = { v1.a, v1.b, v1.c, v2.a, v2.b, v2.c };
	a = v1.b * v2.c - v1.c * v2.b;
	b = v1.a * v2.c - v1.c * v2.a;
	c = v1.a * v2.b - v1.b * v2.a;
}

//Отримати довжину вктора
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