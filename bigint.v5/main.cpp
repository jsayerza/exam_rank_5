#include "bigint.hpp"

int main()
{
	bigint bi0;
	bigint bi1(1);
	bigint bi2("0002");
	bigint bi3 = bi1 + bi2;

	std::cout << "bi0: " << bi0;
	std::cout << "bi1: " << bi1;
	std::cout << "bi2: " << bi2;
	std::cout << "bi3: " << bi3;


	std::cout << std::endl;
	bigint bi11111(11111);
	bigint bi22(22);
	std::cout << "bi11111: " << bi11111;
	std::cout << "bi22: " << bi22;
	std::cout << "bi11111 >> 3: " << (bi11111 >> 3) << std::endl;
	std::cout << "bi11111 << 5: " << (bi11111 << 5) << std::endl;

	std::cout << std::endl;
	bi11111 += bi1;
	std::cout << "bi11111: " << bi11111;

	bi1 += bi11111;
	std::cout << "bi1: " << bi1;

	std::cout << std::endl;
	bigint bi41(41);
	bigint bi1336(1336);
	std::cout << "(41 << 3): " << (bi41 << 3) << std::endl;
	std::cout << "(1336 >> 2): " << (bi1336 >> 2) << std::endl;

	std::cout << std::endl;
	bigint bi42(42);
	bigint bi1337(1337);
	bigint bi42000(42000);
	bigint bi13(13);
	std::cout << "(bi42 << 3 == 42000): " << ((bi42 << 3) == bi42000) << std::endl;
	std::cout << "(bi1337 >> 2 == 13): " << ((bi1337 >> 2) == bi13) << std::endl;

	return (0);
}
