#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
	private:
		std::string _number;
		void delZeros();
	public:
		bigint();
		bigint(std::string number);
		bigint(unsigned int number);
		bigint(const bigint& other);
		~bigint();

		bigint& operator=(const bigint& other);

		std::string getNumber();

		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);

		bigint operator>>(int shift) const;
		bigint operator<<(int shift) const;
		bigint& operator>>=(int shift);
		bigint& operator<<=(int shift);

		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator<=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, bigint& bi);

#endif