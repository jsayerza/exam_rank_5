#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
	private:
		std::string _number;

	public:
		bigint();
		bigint(std::string numberStr);
		bigint(int numberInt);
		bigint(const bigint& other);
		~bigint();

		bigint& operator=(const bigint& other);

		bigint operator<<(size_t digitsShift) const;
		bigint operator>>(size_t digitsShift) const;
		bigint& operator<<=(size_t digitsShift);
		bigint& operator>>=(size_t digitsShift);

		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator>=(const bigint& other) const;

		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);

		std::string getBigint() const;
};

std::ostream& operator<<(std::ostream& oStream, const bigint& number);
std::string delLeadingZeros(std::string numberStr);

#endif