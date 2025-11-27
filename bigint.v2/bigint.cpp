#include "bigint.hpp"

/////////////////////////////////////////////////////////////////////////
bigint::bigint() : _number("0") {}
bigint::bigint(std::string number) : _number(number)
{
	delZeros();
}
bigint::bigint(unsigned int number) : _number(std::to_string(number)) {}
bigint::bigint(const bigint& other) : _number(other._number) {}
bigint::~bigint() {}
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		_number = other._number;
	return (*this);
}


/////////////////////////////////////////////////////////////////////////
bigint bigint::operator+(const bigint& other) const
{
	std::string numThis = _number;
	std::string numThat = other._number;

	int len = 0;
	if (numThis.length() > numThat.length())
	{
		len = numThis.length() - numThat.length();
		numThat = std::string(len, '0') + numThat;
	}
	else
	{
		len = numThat.length() - numThis.length();
		numThis = std::string(len, '0') + numThis;
	}
	
	// std::cout << "\nnumThis: " << numThis << std::endl;
	// std::cout << "numThat: " << numThat << std::endl;
	len = numThis.length();
	int suma = 0;
	int carry = 0;
	std::string result = "";
	int i = len - 1;
	while (i >= 0)
	{
		suma = carry + (numThis[i] - '0') + (numThat[i] - '0');
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


/////////////////////////////////////////////////////////////////////////
bigint bigint::operator>>(int shift) const
{
	if (shift <= 0 || _number == "0")
		return (*this);
	if ((int)_number.length() <= shift)
		return bigint("0");
	return bigint(_number.substr(0, _number.length() - shift));
}
bigint bigint::operator<<(int shift) const
{
	if (shift <= 0 || _number == "0")
		return (*this);
	return bigint(_number + std::string(shift, '0'));
}
bigint& bigint::operator>>=(int shift)
{
	*this = *this >> shift;
	return (*this);
}
bigint& bigint::operator<<=(int shift)
{
	*this = *this << shift;
	return (*this);
}


/////////////////////////////////////////////////////////////////////////
bool bigint::operator==(const bigint& other) const
{
	return (_number == other._number);
}
bool bigint::operator!=(const bigint& other) const
{
	return (_number != other._number);
}

bool bigint::operator>(const bigint& other) const
{
	if (_number.size() > other._number.size())
		return (true);
	if (_number.size() < other._number.size())
		return (false);
	return (_number > other._number);
}
bool bigint::operator<(const bigint& other) const
{
	return (other > *this);
}
bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}
bool bigint::operator<=(const bigint& other) const
{
	return !(other > *this);
}


/////////////////////////////////////////////////////////////////////////
std::string bigint::getNumber()
{
	return (_number);
}

void bigint::delZeros()
{
	if (_number.length() <= 1)
		return;
	int i = 0;
	while (_number[i] == '0')
		i++;
	_number = _number.substr(i, _number.length());
}

/////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, bigint& bi)
{
	os << bi.getNumber();
	return (os);
}
