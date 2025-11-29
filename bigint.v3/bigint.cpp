#include "bigint.hpp"
#include <cstdlib>

bigint::bigint() : _bi("0") {}
bigint::bigint(std::string str) : _bi(str)
{
	delZeros();
}
bigint::bigint(int num) : _bi(std::to_string(num)) {}
bigint::bigint(const bigint& other) : _bi(other._bi) {}
bigint::~bigint(){}
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		_bi = other._bi;
	}
	return (*this);
}

/////////////////////////////////////////////////////////
bool bigint::operator==(const bigint& other) const
{
	if (_bi.length() != other._bi.length())
		return (false);
	return (_bi == other._bi);
}
bool bigint::operator!=(const bigint& other) const
{
	return (!(*this == other));
}

/////////////////////////////////////////////////////////
bigint bigint::operator+(const bigint& other) const
{
	std::string thisStr = this->_bi;
	std::string thatStr = other._bi;
	int len = 0;
	if (thisStr.length() < thatStr.length())
	{
		len = thatStr.length() - thisStr.length();
		thisStr = std::string(len, '0') + thisStr;
	}
	else
	{
		len = thisStr.length() - thatStr.length();
		thatStr = std::string(len, '0') + thatStr;
	}

	std::cout << "thisStr: " << thisStr << std::endl;
	std::cout << "thatStr: " << thatStr << std::endl;

	std::string result = "";
	int carry = 0;
	int suma = 0;
	int i = thisStr.length() - 1;
	while (i >= 0)
	{
		suma = carry + (thisStr[i] - '0') + (thatStr[i] - '0');
		carry = suma / 10;
		result = (char)((suma % 10) + '0') + result;
		// std::cout << "i: " << i;
		// std::cout << " suma: " << suma;
		// std::cout << " carry: " << carry;
		// std::cout << " result: " << result << std::endl;
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


/////////////////////////////////////////////////////////
bigint& bigint::operator<<(int shift)
{
	if (shift < 2)
		return (*this);
	_bi = _bi + std::string(shift, '0');
	return (*this);
}
bigint& bigint::operator>>(int shift)
{
	int len = _bi.length();
	if (shift >= len)
		_bi = "0";
	else
		_bi = _bi.substr(0, len - shift);
	return (*this);
}

/////////////////////////////////////////////////////////
std::string& bigint::getBi()
{
	return (_bi);
}

void bigint::delZeros()
{
	if (_bi.length() < 2)
		return;
	size_t i = 0;
	while (i < _bi.length() && _bi[i] == '0')
		i++;
	_bi = _bi.substr(i, _bi.length());
}

std::ostream& operator<<(std::ostream& os, bigint& bi)
{
	os << bi.getBi();
	return (os);
}
