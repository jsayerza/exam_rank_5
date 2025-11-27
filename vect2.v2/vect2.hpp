#ifndef VECT2_HPP
# define VECT2_HPP

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

		vect2& operator=(const vect2& other);
		int operator[](int index) const;
		bool operator==(const vect2& other) const;

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2 operator*(int value) const;
};

std::ostream& operator<<(std::ostream& oStream, const vect2& other);

#endif