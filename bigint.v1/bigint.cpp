#include "bigint.hpp"

void bigint::delZeros()
{
	int len = _str.length();
	if (len < 2)
		return;
	int i = 0;
	while (i < len && _str[i] == '0')
	{
		i++;
	}
	_str = _str.substr(i, len - i);
}

/////////////////
bigint::bigint() : _str("0") {}
bigint::bigint(std::string str) : _str(str)
{
	delZeros();
}
bigint::bigint(int num) : _str(std::to_string(num)) {}
bigint::bigint(const bigint& other) : _str(other._str) {}
bigint::~bigint() {}
bigint bigint::operator=(const bigint& other)
{
	if (this != &other)
		_str = other._str;
	return (*this);
}

//Addition
bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return (*this);
}
bigint bigint::operator+(const bigint& other) const
{
	std::string thisStr = _str;
	std::string thatStr = other._str;
	int thisStrLen = thisStr.length();
	int thatStrLen = thatStr.length();

	int len = 0;
	if (thisStrLen > thatStrLen)
	{
		len = thisStrLen - thatStrLen;
		thatStr = std::string(len, '0') + thatStr;
	}
	else
	{
		len = thatStrLen - thisStrLen;
		thisStr = std::string(len, '0') + thisStr;
	}

	std::string result = "";
	int suma = 0;
	int carry = 0;
	int i = thisStr.length() - 1;
	while (i >= 0)
	{
		suma = carry + (thisStr[i] - '0') + (thatStr[i] - '0');
		carry = (suma / 10);
		result = (char)((suma % 10) + '0') + result;
		i--;
	}
	if (carry)
		result = '1' + result;

	return bigint(result);
}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return (*this);
}
bigint bigint::operator++(int)
{
	bigint temp = *this;
	*this = *this + bigint(1);
	return (temp);
}



//Comparation
bool bigint::operator==(const bigint& other) const
{
	return (_str == other._str);
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}
bool bigint::operator>(const bigint& other) const
{
	std::string thisStr = _str;
	std::string thatStr = other._str;
	int thisStrLen = thisStr.length();
	int thatStrLen = thatStr.length();
	
	if (thisStrLen != thatStrLen)
		return (thisStrLen > thatStrLen);
	return (_str > other._str);
}
bool bigint::operator<(const bigint& other) const
{
	return (other > *this);
}
bool bigint::operator>=(const bigint& other) const
{
	return (*this > other || *this == other);
}
bool bigint::operator<=(const bigint& other) const
{
	return (other > *this || *this == other);
}

//digitshift int
bigint bigint::operator>>(unsigned int shift) const
{
	std::string str = "0";
	unsigned int len = _str.length();
	if (shift >= len)
		str = "0";
	else
		str = _str.substr(0, len - shift);
	return bigint(str);
}
bigint bigint::operator<<(unsigned int shift) const
{
	std::string str = "0";
	if (_str == "0")
		str = "0";
	else
		str = _str + std::string(shift, '0');
	return bigint(str);
}

bigint& bigint::operator>>=(unsigned int shift)
{
	unsigned int len = _str.length();
	if (shift >= len)
		_str = "0";
	else
		_str = _str.substr(0, len - shift);
	return (*this);
}
bigint& bigint::operator<<=(unsigned int shift)
{
	if (_str == "0")
		_str = "0";
	else
		_str = _str + std::string(shift, '0');
	return (*this);
}


//digitshift bigint
unsigned int stringToUInt(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

bigint bigint::operator>>(const bigint& shift) const
{
	bigint temp;
	temp = (*this) >> stringToUInt(shift._str);
	return bigint(temp);
}
bigint bigint::operator<<(const bigint& shift) const
{
	bigint temp;
	temp = (*this) << stringToUInt(shift._str);
	return bigint(temp);
}

bigint& bigint::operator>>=(const bigint& shift)
{
	*this = (*this) >> stringToUInt(shift._str);
	return (*this);
}
bigint& bigint::operator<<=(const bigint& shift)
{
	*this = (*this) << stringToUInt(shift._str);
	return (*this);
}


/////////////////////////////
std::string bigint::getStr() const
{
	return (_str);
}
		
std::ostream& operator<<(std::ostream& s, const bigint& bi)
{
	s << bi.getStr() << std::endl;
	return (s);
}

