#ifndef VECT2_HPP
# define VECT2_HPP

# include <ostream>
# include <iostream>

class vect2
{
	private:
		int _x;
		int _y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2& other);
		~vect2();
		vect2& operator=(const vect2 other);

		//operator[]
		int operator[](int index) const;
		int& operator[](int index);

		//addition
		vect2 operator+(const vect2 other) const;
		vect2& operator+=(const vect2 other);
		vect2 operator++(int);
		vect2& operator++();
		
		//subtraction
		vect2 operator-(const vect2 other) const;
		vect2& operator-=(const vect2 other);
		vect2 operator--(int);
		vect2& operator--();
		// -v
		vect2& operator-();

		//multiplication by a scaler	
		vect2 operator*(int scaler) const;
		vect2& operator*=(int scaler);

		//comparison
		bool operator==(const vect2 other) const;
		bool operator!=(const vect2 other) const;
		

};

vect2 operator*(int scaler, const vect2 other);

std::ostream& operator<<(std::ostream& s, const vect2& v);


#endif
