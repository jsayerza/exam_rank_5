#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <ostream>
#include <iostream>
#include <string>

class bigint
{
	private:
		std::string _str;
		void delZeros();
	public:
		bigint();
		bigint(std::string str);
		bigint(int num);
		bigint(const bigint& other);
		~bigint();
		bigint& operator=(const bigint& other);

		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);

		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;

		bigint& operator>>(int shift);
		bigint& operator<<(int shift);

		std::string getBi();
};

std::ostream& operator<<(std::ostream& s, bigint& bi);

#endif