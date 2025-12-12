# include "bigint.hpp"

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
bigint::bigint(unsigned int num) : _str(std::to_string(num)) {}
bigint::bigint(std::string str) : _str(str)
{
	delZeros();
}
bigint::bigint(const bigint& other) : _str(other._str) {}
bigint::~bigint() {}
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		_str = other._str;
	return (*this);
}

//addition
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
		carry = suma / 10;
		result = (char)((suma % 10) + '0') + result;
		i--;
	}
	if (carry)
		result = '1' + result;

	return bigint(result);
}

// ++bi
bigint& bigint::operator++()
{
	*this +=  bigint(1);
	return (*this);
}
// bi++
bigint bigint::operator++(int)
{
	bigint temp = *this;
	*this +=  bigint(1);
	return bigint(temp);
}


//"digitshift"

unsigned int strToUInt(std::string str)
{
	unsigned int res = 0;
	std::stringstream ss(str);
	ss >> res;
	return (res);
}

bigint bigint::operator>>(unsigned int shift) const
{
	unsigned int len = _str.length();
	std::string str = "";
	if (shift >= len)
		str = "0";
	else
		str = _str.substr(0, len - shift);
	return bigint(str);
}
bigint& bigint::operator>>=(unsigned int shift)
{
	*this = *this >> shift;
	return (*this);
}
bigint bigint::operator>>(const bigint& other) const
{
	unsigned int shift = strToUInt(other._str);
	return bigint(*this >> shift);
}
bigint& bigint::operator>>=(const bigint& other)
{
	unsigned int shift = strToUInt(other._str);
	return (*this >>= shift);
}


bigint bigint::operator<<(unsigned int shift) const
{
	std::string str = "";
	if (_str == "0")
		str = "0";
	else
		str = _str + std::string(shift, '0');
	return bigint(str);
}
bigint& bigint::operator<<=(unsigned int shift)
{
	*this = *this << shift;
	return (*this);
}
bigint bigint::operator<<(const bigint& other) const
{
	unsigned int shift = strToUInt(other._str);
	return bigint(*this << shift);
}
bigint& bigint::operator<<=(const bigint& other)
{
	unsigned int shift = strToUInt(other._str);
	return (*this <<= shift);
}


//comparison

bool bigint::operator==(const bigint& other) const
{
	return (_str == other._str);
}
bool bigint::operator!=(const bigint& other) const
{
	return (!(_str == other._str));
}
bool bigint::operator<(const bigint& other) const
{
	int thisLen = _str.length();
	int thatLen = other._str.length();
	if (thisLen != thatLen)
		return (thisLen < thatLen);
	else
		return (_str < other._str);
}
bool bigint::operator>(const bigint& other) const
{
	return (!(*this < other) && (*this != other));
}
bool bigint::operator<=(const bigint& other) const
{
	return ((*this < other) || (*this == other));
}
bool bigint::operator>=(const bigint& other) const
{
	return ((*this > other) || (*this == other));
}



std::string bigint::getStr() const
{
	return (_str);
}

std::ostream& operator<<(std::ostream& s, const bigint& bi)
{
	s << bi.getStr() << std::endl;
	return (s);
}

