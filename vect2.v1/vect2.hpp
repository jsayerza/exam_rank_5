#ifndef VECT2
# define VECT2

# include <iostream>

class vect2
{
	private:
		int _value1;
		int _value2;

	public:
		vect2();
		vect2(int value1, int value2);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);
		~vect2();

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2 operator*(int value) const;

		int operator[](int index) const;
		bool operator==(const vect2& other) const;
};

std::ostream& operator<<(std::ostream& oStream, const vect2& vect);

#endif