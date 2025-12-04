#include "bigint.hpp"

void bigint::delZeros()
{
	int len = _str.length();
	if (len < 2)
		return;
	int i = 0;
	while (i < len && _str[i] == '0')
		i++;
	_str = _str.substr(i, len - i);
}

bigint::bigint() : _str("0") {}
bigint::bigint(std::string str) : _str(str)
{
	delZeros();
}
bigint::bigint(int num) : _str(std::to_string(num)) {}
bigint::bigint(const bigint& other) : _str(other._str) {}
bigint::~bigint(){}
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		_str = other._str;
	}
	return (*this);
}

bigint bigint::operator+(const bigint& other) const
{
	std::string thisStr = _str;
	std::string thatStr = other._str;

	int len = 0;
	if (thisStr.length() > thatStr.length())
	{
		len = thisStr.length() - thatStr.length();
		thatStr = std::string(len, '0') + thatStr;
	}
	else
	{
		len = thatStr.length() - thisStr.length();
		thisStr = std::string(len, '0') + thisStr;
	}

	std::string result = "";
	int suma = 0;
	int carry = 0;
	int i = thisStr.length() - 1;
	while (i >= 0)
	{
		suma = carry + (thisStr[i] - '0') + (thatStr[i] - '0');
		carry = suma / 10;
		result = (char)((suma % 10) + '0') + result;
		i--;
	}
	if (carry)
		result = "1" + result;

	return bigint(result);
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return (*this);
}

bool bigint::operator==(const bigint& other) const
{
	if (_str.length() != other._str.length())
		return (false);
	return (_str == other._str);
}
bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

bigint& bigint::operator>>(int shift)
{
	int len = _str.length();
	if (shift >= len)
		_str = "0";
	else
		_str = _str.substr(0, len - shift);
	return (*this);
}
bigint& bigint::operator<<(int shift)
{
	_str = _str + std::string(shift, '0');
	return (*this);
}

std::string bigint::getStr()
{
	return (_str);
}

std::ostream& operator<<(std::ostream& s, bigint& bi)
{
	s << bi.getStr() << std::endl;
	return (s);
}

