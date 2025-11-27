#include "vect2.hpp"

int main()
{

	vect2 vec0;
	vect2 vec1(1, 2);
	vect2 vec2(10, 20);

	std::cout << "vec0: " << vec0;
	std::cout << "vec1: " << vec1;
	std::cout << "vec2: " << vec2;

	vect2 vec4 = vec2 + vec1;
	std::cout << "\nvec1: " << vec1;
	std::cout << "vec2: " << vec2;
	std::cout << "vec4: " << vec4;

	vect2 vec3 = vec0 - vec2;
	std::cout << "\nvec0: " << vec0;
	std::cout << "vec2: " << vec2;
	std::cout << "vec3: " << vec3;

	vect2 vec5 = vec1 * 3;
	std::cout << "\nvec1: " << vec1;
	std::cout << "vec5: " << vec5;
	std::cout << "vec5[0]: " << vec5[0] << std::endl;
	std::cout << "vec5[1]: " << vec5[1] << std::endl;

	if (vect2(2,2) * 2 == vect2(4,4))
		std::cout << "OK!" << std::endl;
	else
		std::cout << "KO!" << std::endl;

	if (vect2(2,2) * 2 == vect2(4,5))
		std::cout << "OK!" << std::endl;
	else
		std::cout << "KO!" << std::endl;

	return (0);
}