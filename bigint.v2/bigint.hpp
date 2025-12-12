#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>
# include <iostream>
# include <ostream>
# include <sstream>

class bigint
{
	private:
		std::string _str;
		void delZeros();
	public:
		bigint();
		bigint(unsigned int num);
		bigint(std::string str);
		bigint(const bigint& other);
		~bigint();
		bigint& operator=(const bigint& other);

		//addition
		bigint& operator+=(const bigint& other);
		bigint operator+(const bigint& other) const;
		// ++bi
		bigint& operator++();
		// bi++
		bigint operator++(int);

		
		//"digitshift"
		bigint& operator>>=(unsigned int shift);
		bigint operator>>(unsigned int shift) const;
		bigint& operator>>=(const bigint& other);
		bigint operator>>(const bigint& other) const;

		bigint& operator<<=(unsigned int shift);
		bigint operator<<(unsigned int shift) const;
		bigint& operator<<=(const bigint& other);
		bigint operator<<(const bigint& other) const;

		//comparison
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;

		std::string getStr() const;
};


std::ostream& operator<<(std::ostream& s, const bigint& bi);

#endif
