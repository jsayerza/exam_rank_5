#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int x, int y) : _x(x), _y(y) {}
vect2::vect2(const vect2& other) : _x(other._x), _y(other._y) {}
vect2::~vect2() {}
vect2 vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

//////////////////////////////////////
int vect2::operator[](int index) const
{
	return (index == 0 ? _x : _y);
}
int& vect2::operator[](int index)
{
	return (index == 0 ? _x : _y);
}



///////////////////////////////////
// v++
vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	_x += 1;
	_y += 1;
	return (temp);
}
vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	_x -= 0;
	_y -= 0;
	return (temp);
}

// ++v
vect2& vect2::operator++()
{
	_x += 1;
	_y += 1;
	return (*this);
}
vect2& vect2::operator--()
{
	_x -= 1;
	_y -= 1;
	return (*this);
}

// -v
vect2& vect2::operator-()
{
	_x *= -1;
	_y *= -1;
	return (*this);
}


///////////////////////////////
vect2& vect2::operator+=(const vect2& other)
{
	_x += other._x;
	_y += other._y;
	return (*this);
}
vect2& vect2::operator-=(const vect2& other)
{
	_x -= other._x;
	_y -= other._y;
	return (*this);
}
vect2& vect2::operator*=(int scaler)
{
	_x *= scaler;
	_y *= scaler;
	return (*this);
}


////////////////////////////////////////////////
vect2 vect2::operator+(const vect2& other) const
{
	return vect2(_x + other._x, _y + other._y);
}
vect2 vect2::operator-(const vect2& other) const
{
	return vect2(_x - other._x, _y - other._y);
}
vect2 vect2::operator*(int scaler) const
{
	return vect2(_x * scaler, _y * scaler);
}


/////////////////////////////////////////
bool vect2::operator==(const vect2& other) const
{
	return (_x == other._x && _y == other._y);
}
bool vect2::operator!=(const vect2& other) const
{
	return !(*this == other);
}

/////////////////////////////////////////////////////////
vect2 operator*(int scaler, const vect2& other)
{
	return vect2(other * scaler);
}

std::ostream& operator<<(std::ostream& s, const vect2& v)
{
	s << "{" << v[0] << ", " << v[1] << "}" << std::endl;
	return (s);
}


