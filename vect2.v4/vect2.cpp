#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int x, int y) : _x(x), _y(y) {}
vect2::vect2(const vect2& other) : _x(other._x), _y(other._y) {}
vect2::~vect2(){}
vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

int vect2::operator[](int index) const
{
	return (index == 0 ? _x : _y);
}
int& vect2::operator[](int index)
{
	return (index == 0 ? _x : _y);
}

vect2 vect2::operator+(const vect2& other) const
{
	return vect2(_x + other._x, _y + other._y);
}
vect2& vect2::operator+=(const vect2& other)
{
	_x += other._x;
	_y += other._y;
	return (*this);
}

vect2 vect2::operator-(const vect2& other) const
{
	return vect2(_x - other._x, _y - other._y);
}
vect2& vect2::operator-=(const vect2& other)
{
	_x -= other._x;
	_y -= other._y;
	return (*this);
}

vect2 vect2::operator*(int scaler) const
{
	return vect2(_x * scaler, _y * scaler);
}
vect2& vect2::operator*=(int scaler)
{
	_x *= scaler;
	_y *= scaler;
	return (*this);
}

int vect2::operator==(const vect2& other) const
{
	return (_x == other._x && _y == other._y);
}
int vect2::operator!=(const vect2& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& s, vect2& v)
{
	s << "{" << v[0] << ", " << v[1] << "}" << std::endl;
	return (s);
}
