#include "bigint.hpp"

std::string delLeadingZeros(std::string numberStr)
{
	size_t i = 0;
	while (numberStr[i] == '0' && i < numberStr.length() - 1)
		i++;
	return (numberStr.substr(i, numberStr.length()));
}


////////////////////////////////////////////////////////
bigint::bigint() : _number("0") {}
bigint::bigint(std::string numberStr) : _number(numberStr)
{
	_number = delLeadingZeros(_number);
}
bigint::bigint(int numberInt) : _number(std::to_string(numberInt)) {}
bigint::bigint(const bigint& other) : _number(other._number) {}
bigint::~bigint() {}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		_number = other._number;
	return (*this);
}


////////////////////////////////////////////////////////
bigint bigint::operator<<(size_t digitsShift) const
{
	if (digitsShift <= 0 || _number == "0")
		return (*this);
	return bigint(_number + std::string(digitsShift, '0'));
}

bigint bigint::operator>>(size_t digitsShift) const
{
	if (digitsShift <= 0 || _number == "0")
		return (*this);
	if (digitsShift >= _number.length())
		return bigint(0);
	return bigint(_number.substr(0, _number.length() - digitsShift));
}

bigint& bigint::operator<<=(size_t digitsShift)
{
	*this = *this << digitsShift;
	return (*this);
}

bigint& bigint::operator>>=(size_t digitsShift)
{
	*this = *this >> digitsShift;
	return (*this);
}


////////////////////////////////////////////////////////
bool bigint::operator==(const bigint& other) const
{
	return (this->_number == other._number);
}


bool bigint::operator!=(const bigint& other) const
{
	return (this->_number != other._number);
}

bool bigint::operator<(const bigint& other) const
{
	if (_number.length() != other._number.length())
		return (_number.length() < other._number.length());
	return (_number < other._number);
}

bool bigint::operator<=(const bigint& other) const
{
	return !(*this > other);
}

bool bigint::operator>(const bigint& other) const
{
	return (other < *this);
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}


////////////////////////////////////////////////////////
bigint bigint::operator+(const bigint& other) const
{
	std::string thisStr = _number;
	std::string otherStr = other._number;

	if (thisStr.length() > otherStr.length())
		otherStr = std::string(thisStr.length() - otherStr.length(), '0') + otherStr;
	else
		thisStr = std::string(otherStr.length() - thisStr.length(), '0') + thisStr;

	bigint result;
	std::string resultStr = "";
	int i = thisStr.length() - 1;
	int carry = 0;
	int suma = 0;
	while (i >= 0)
	{
		suma = carry + (thisStr[i] - '0') + (otherStr[i] - '0');
		carry = suma / 10;
		resultStr = (char)((suma % 10) + '0') + resultStr;
		i--;
	}
	if (carry)
		resultStr = "1" + resultStr;
	result._number = resultStr;
	
	return (result);
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return (*this);
}

////////////////////////////////////////////////////////
std::string bigint::getBigint() const
{
	return (_number);
}

std::ostream& operator<<(std::ostream& oStream, const bigint& number)
{
	oStream << number.getBigint();
	return (oStream);
}