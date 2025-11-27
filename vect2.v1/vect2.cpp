#include "vect2.hpp"

vect2::vect2() : _value1(0), _value2(0)
{}

vect2::vect2(int value1, int value2) : _value1(value1), _value2(value2)
{}

vect2::vect2(const vect2& other) : _value1(other._value1), _value2(other._value2)
{}

vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		_value1 = other._value1;
		_value2 = other._value2;
	}
	return (*this);
}

vect2::~vect2()
{}

int vect2::operator[](int index) const
{
	if (index == 0) 
		return (_value1);
	else if (index == 1)
		return (_value2);
	return (0);
}

vect2 vect2::operator+(const vect2& other) const
{
	return vect2(_value1 + other._value1, _value2 + other._value2);
}

vect2 vect2::operator-(const vect2& other) const
{
	return vect2(_value1 - other._value1, _value2 - other._value2);
}

vect2 vect2::operator*(int value) const
{
	return vect2(_value1 * value, _value2 * value);
}

bool vect2::operator==(const vect2& other) const
{
	return (_value1 == other._value1 && _value2 == other._value2);
}

std::ostream& operator<<(std::ostream& oStream, const vect2& vect)
{
	oStream << "{" << vect[0] << ", " << vect[1] << "}";
	return (oStream);
}
