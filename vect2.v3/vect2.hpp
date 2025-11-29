#ifndef VECT2_HPP
# define VECT2_HPP

#include <ostream>

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
		vect2& operator=(const vect2& other);

		int operator[](int index) const;
		int& operator[](int index);

		vect2 operator+(const vect2& other) const;
		vect2& operator+=(const vect2& other);
		vect2 operator-(const vect2& other) const;
		vect2& operator-=(const vect2& other);
		vect2 operator*(int scalar) const;
		vect2& operator*=(int scalar);

		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;

};
std::ostream& operator<<(std::ostream& s, vect2& v);

#endif