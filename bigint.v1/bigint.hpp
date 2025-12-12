#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <ostream>
# include <sstream>
# include <iostream>
# include <string>
# include <cstdlib>

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
		bigint operator=(const bigint& other);

		//Addition
		bigint& operator+=(const bigint& other);
		bigint operator+(const bigint& other) const;
		bigint& operator++();
		bigint operator++(int);

		//digitshift int
		bigint operator<<(unsigned int shift) const;
		bigint operator>>(unsigned int shift) const;
		bigint& operator<<=(unsigned int shift);
		bigint& operator>>=(unsigned int shift);

		//digitshift bigint
		bigint operator<<(const bigint& shift) const;
		bigint operator>>(const bigint& shift) const;
		bigint& operator<<=(const bigint& shift);
		bigint& operator>>=(const bigint& shift);

		//Comparation
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator<=(const bigint& other) const;

		std::string getStr() const;
		
};

std::ostream& operator<<(std::ostream& s, const bigint& bi);

#endif
