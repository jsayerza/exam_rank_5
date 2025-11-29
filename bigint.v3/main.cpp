#include "bigint.hpp"

int main()
{
	bigint bi0;
	bigint bi1(1);
	bigint bi2("00002");
	bigint bi20("000020");
	bigint bi3 = bi2;
	bigint bi4(bi2);
	bigint bi1234(1234);
	bigint bi67890("0067890");

	std::cout << "bi0: " << bi0 << std::endl;
	std::cout << "bi1: " << bi1 << std::endl;
	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi3: " << bi3 << std::endl;
	std::cout << "bi4: " << bi4 << std::endl;
	std::cout << "bi20: " << bi20 << std::endl;
	std::cout << "bi1234: " << bi1234 << std::endl;
	std::cout << "bi67890: " << bi67890 << std::endl;

	std::cout << std::endl;
	std::cout << "(bi1 == bi2): " << (bi1 == bi2) << std::endl;
	std::cout << "(bi1 != bi2): " << (bi1 != bi2) << std::endl;
	std::cout << "(bi2 == bi3): " << (bi2 == bi3) << std::endl;
	std::cout << "(bi2 != bi3): " << (bi2 != bi3) << std::endl;

	std::cout << std::endl;
	bigint bi1235 = bi1234 + bi1;
	std::cout << "bi1235 = bi1234 + bi1: " << bi1235 << std::endl;

	std::cout << std::endl;
	bigint bi1236 = bi2 + bi1234;
	std::cout << "bi1236 = bi2 + bi1234: " << bi1236 << std::endl;

	std::cout << std::endl;
	bigint bi1254(bi1234);
	bi1254 += bi20;
	std::cout << "bi1254 += bi20: " << bi1254 << std::endl;

	std::cout << std::endl;
	std::cout << "bi1254 << 3: " << (bi1254 << 3) << std::endl;
	std::cout << "bi1254 >> 5: " << (bi1254 >> 5) << std::endl;
	std::cout << "bi1254 >> 5: " << (bi1254 >> 5) << std::endl;

	return (0);
}