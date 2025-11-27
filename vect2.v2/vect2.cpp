#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int x, int y) : _x(x), _y(y) {}
vect2::vect2(const vect2& other) : _x(other._x), _y(other._y) {}
vect2::~vect2() {}

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
	if (index == 0)
		return (_x);
	else if (index == 1)
		return (_y);
	else
		return (0);
}

bool vect2::operator==(const vect2& other) const
{
	return (_x == other._x && _y == other._y);
}

vect2 vect2::operator+(const vect2& other) const
{
	return vect2(_x + other._x, _y + other._y);
}

vect2 vect2::operator-(const vect2& other) const
{
	return vect2(_x - other._x, _y - other._y);
}

vect2 vect2::operator*(int value) const
{
	return vect2(_x  * value, _y * value);
}

std::ostream& operator<<(std::ostream& oStream, const vect2& vec)
{
	oStream << "{" << vec[0] << ", "  << vec[1] << "}";
	return (oStream);
}