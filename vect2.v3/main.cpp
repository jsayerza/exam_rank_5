#include "vect2.hpp"
#include <iostream>
#include <ostream>

int main()
{
	vect2 v1;
	vect2 v2(1, 1);
	vect2 v3(2, 3);

	std::cout << "v1: " << v1;
	std::cout << "v2: " << v2;
	std::cout << "v3: " << v3;

	vect2 v4 = (v2 + v3);
	std::cout << "v4 = (v2 + v3): " << v4;

	v4 += v2;
	std::cout << "v4 += v2: " << v4;

	vect2 v5 = (v2 - v3);
	std::cout << "v5 = (v2 - v3): " << v5;

	v5 -= v2;
	std::cout << "v5 -= v2: " << v5;

	vect2 v6 = v3 * 2;
	std::cout << "v6 = v3 * 2: " << v6;

	v6 *= 2;
	std::cout << "v6 *= 2: " << v6;

	std::cout << "v6[0]: " << v6[0];
	std::cout << "\nv6[1]: " << v6[1];
	std::cout << "\nv6[2]: " << v6[2];
	std::cout << "\nv6[-1]: " << v6[-1];

	vect2 v7(v6);
	vect2 v8 = v5;
	std::cout << "\nv7 == v6: " << (v7 == v6);
	std::cout << "\nv7 != v6: " << (v7 != v6);
	std::cout << "\nv8 == v5: " << (v8 == v5);
	std::cout << "\nv8 != v5: " << (v8 != v5);

	std::cout << "\nv6[0] = 666: " << (v6[0] = 666);
	std::cout << "\nv6: " << v6;
	std::cout << "\nv6[1] = 42: " << (v6[1] = 42);
	std::cout << "\nv6: " << v6;
	std::cout << "\nv6[-1] = 777: " << (v6[1] = 777);
	std::cout << "\nv6: " << v6;


	return (0);
}