#include "vect2.hpp"

int main()
{
	vect2 vec0;
	vect2 vec1(1,2);
	vect2 vec2(vec1);
	vect2 vec3 = vec0;

	std::cout << "vec0: " << vec0 << std::endl;
	std::cout << "vec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;
	std::cout << "vec3: " << vec3 << std::endl;

	vect2 vec4 = vec1 + vec2;
	std::cout << "\nvec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;
	std::cout << "vec4: " << vec4 << std::endl;

	vect2 vec5 = vec2 - vec4;
	std::cout << "\nvec2: " << vec2 << std::endl;
	std::cout << "vec4: " << vec4 << std::endl;
	std::cout << "vec5: " << vec5 << std::endl;

	vect2 vec6 = vec5 * 10;
	std::cout << "\nvec5: " << vec5 << std::endl;
	std::cout << "vec6: " << vec6 << std::endl;

	if (vec0 == vec3)
		std::cout << "\nOK!" << std::endl;
	else
		std::cout << "\nNO OK!" << std::endl;

	if (vec0 == vec1)
		std::cout << "\nOK!" << std::endl;
	else
		std::cout << "\nNO OK!" << std::endl;


	return (0);
}