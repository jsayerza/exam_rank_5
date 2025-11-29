#include <ostream>
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

////////////////////////////////////////////////////
int vect2::operator[](int index) const
{
	if (index == 0)
		return (this->_x);
	else
		return (this->_y);
}
int& vect2::operator[](int index)
{
	if (index == 0)
		return (this->_x);
	else
		return (this->_y);
}


////////////////////////////////////////////////////
vect2 vect2::operator+(const vect2& other) const
{
	int x = _x + other._x;
	int y = _y + other._y;
	return vect2(x, y);
}
vect2& vect2::operator+=(const vect2& other)
{
	_x += other._x;
	_y += other._y;
	return (*this);
}
vect2 vect2::operator-(const vect2& other) const
{
	int x = _x - other._x;
	int y = _y - other._y;
	return vect2(x, y);
}
vect2& vect2::operator-=(const vect2& other)
{
	_x -= other._x;
	_y -= other._y;
	return (*this);
}
vect2 vect2::operator*(int scalar) const
{
	int x = _x * scalar;
	int y = _y * scalar;
	return vect2(x, y);
}
vect2& vect2::operator*=(int scalar)
{
	_x *= scalar;
	_y *= scalar;
	return (*this);
}

////////////////////////////////////////////////////
bool vect2::operator==(const vect2& other) const
{
	return ((_x == other._x && _y == other._y));
}
bool vect2::operator!=(const vect2& other) const
{
	return (!(_x == other._x && _y == other._y));
}


////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& s, vect2& v)
{
	s << "{" << v[0] << ", " << v[1] << "}" << std::endl;
	return (s);
}
