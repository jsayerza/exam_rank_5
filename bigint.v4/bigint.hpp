#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <ostream>
# include <iostream>
# include <sstream>
# include <string>

class bigint
{
	private:
		std::string _str;
		void delZeros();
	public:
		bigint();
		bigint(int num);
		bigint(std::string str);
		bigint(const bigint& other);
		~bigint();
		bigint& operator=(const bigint& other);

		//addition
		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);
		bigint operator++(int);
		bigint& operator++();

		//"digitshift" bi/10
		bigint operator>>(unsigned int shift) const;
		bigint& operator>>=(unsigned int shift);
		bigint operator>>(const bigint& other) const;
		bigint& operator>>=(const bigint& other);

		//"digitshift" bi*10
		bigint operator<<(unsigned int shift) const;
		bigint& operator<<=(unsigned int shift);
		bigint operator<<(const bigint& other) const;
		bigint& operator<<=(const bigint& other);

		//comparison
		bool operator>(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator<=(const bigint& other) const;

		std::string getStr() const;
		
};

std::ostream& operator<<(std::ostream& s, const bigint& bi);

#endif
