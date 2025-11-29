#include "vect2.hpp"

int main()
{
	vect2 v0;
	vect2 v1(1, 1);
	vect2 v2 = v1 * 2;
	vect2 v4 = v2 * 2;
	vect2 v3 = v4 - v1;
	std::cout << "v0: " << v0;
	std::cout << "v1: " << v1;
	std::cout << "v2: " << v2;
	std::cout << "v3: " << v3;
	std::cout << "v4: " << v4;

	std::cout << std::endl;
	vect2 v58(5, 8);
	std::cout << "v58: " << v58;
	v58[-1] = 123;
	std::cout << "v58: " << v58;
	v58[0] = 42;
	std::cout << "v58: " << v58;
	v58[1] = 666;
	std::cout << "v58: " << v58;

	std::cout << std::endl;
	std::cout << "v58[0]: " << v58[0] << std::endl;
	std::cout << "v58[1]: " << v58[1] << std::endl;

	std::cout << std::endl;
	std::cout << "(vect2(2,2) * 2 == vect2(4,4)): " << (vect2(2,2) * 2 == vect2(4,4)) << std::endl;

	return (0);
}