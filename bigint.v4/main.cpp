#include "bigint.hpp"

int main()
{
	bigint bi0;
	bigint bi1(1);
	bigint bi2("0002");
	bigint bi3(bi2);
	bigint bi4 = bi2;

	std::cout << "bi0: " << bi0;
	std::cout << "bi1: " << bi1;
	std::cout << "bi2: " << bi2;
	std::cout << "bi3: " << bi3;
	std::cout << "bi4: " << bi4;

	std::cout << std::endl;
	bi3 += bi1;
	std::cout << "bi3: " << bi3;

	std::cout << std::endl;
	bigint bi5 = bi2 + bi3;
	std::cout << "bi5 = bi2 + bi3: " << bi5;

	std::cout << std::endl;
	bigint bi123(123);
	bigint bi124 = bi123 + bi1;
	std::cout << "bi124 = bi123 + bi1: " << bi124;

	std::cout << std::endl;
	bigint bi125 = bi2 + bi123;
	std::cout << "bi125 = bi2 + bi123: " << bi125;

	std::cout << std::endl;
	std::cout << "(bi2 == bi4): " << (bi2 == bi4) << std::endl;
	std::cout << "(bi2 != bi4): " << (bi2 != bi4) << std::endl;
	std::cout << "(bi2 == bi1): " << (bi2 == bi3) << std::endl;
	std::cout << "(bi2 != bi1): " << (bi2 != bi3) << std::endl;

	std::cout << std::endl;
	std::cout << "(bi125 >> 3): " << (bi125 >> 3) << std::endl;
	std::cout << "(bi125 << 4): " << (bi125 << 4) << std::endl;
	std::cout << "(bi125 << 4): " << (bi125 << 4) << std::endl;

	return (0);
}