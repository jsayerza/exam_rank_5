#include "bigint.hpp"

int main()
{
	bigint bi0;
	bigint bi1(1);
	bigint bi2("00002");
	bigint bi123("0123");
	bigint bi99999("099999");
	std::cout << "bi0: " << bi0;
	std::cout << "bi1: " << bi1;
	std::cout << "bi2: " << bi2;
	std::cout << "bi123: " << bi123;
	std::cout << "bi99999: " << bi99999;
	bigint bi3 = bi1 + bi2;
	std::cout << "bi3: " << bi3;
	bigint bix1 = bi123 + bi99999;
	bigint bix2 = bi99999 + bi123;
	std::cout << "bix1: " << bix1;
	std::cout << "bix2: " << bix2;
	bix2 += bi1;
	std::cout << "bix2+1: " << bix2;
	std::cout << "bix1 == bix2: " << (bix1 == bix2) << std::endl;
	std::cout << "bix1 != bix2: " << (bix1 != bix2) << std::endl;
	std::cout << "bix1 == bi2: " << (bix1 == bi2) << std::endl;
	std::cout << "bix1 != bi2: " << (bix1 != bi2) << std::endl;
//	bix1 << 3;
	std::cout << "bix1 << 3: " << (bix1 << 3);
	std::cout << "bix1 >> 5: " << (bix1 >> 5);

	std::cout << "bix1 << -3: " << (bix1 << -3);
	std::cout << "bix1 >> -5: " << (bix1 >> -5);
	
	bigint bi1234("-01234");
	std::cout << "bi1234: " << bi1234;

	bigint bi000("000");
	std::cout << "bi000: " << bi000;

	return (0);
}
