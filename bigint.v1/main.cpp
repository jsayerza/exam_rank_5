#include "bigint.hpp"

int main()
{

	bigint bi0;
	bigint bi1("00001234567890");
	bigint bi2 = bi1;
	bigint bi3(bi0);

	std::cout << "bi0: " << bi0;
	std::cout << "bi1: " << bi1;
	std::cout << "bi2: " << bi2;
	std::cout << "bi3: " << bi3;

	bi2 << 3;
	std::cout << "\nbi2: " << bi2;

	bi2 >> (3 + 5);
	std::cout << "\nbi2: " << bi2;


	bi1 >> 9;
	std::cout << "\nbi1: " << bi1;

	bi1 >> 1;
	std::cout << "\nbi1: " << bi1;

	bi1 >> 0;
	std::cout << "\nbi1: " << bi1;

	bi1 >> 2;
	std::cout << "\nbi1: " << bi1;

	bigint bi4(0);
	std::cout << "\nbi4: " << bi4;

	bi4 >> 1;
	std::cout << "\nbi4: " << bi4;

	bigint bi13(3210);
	std::cout << "\nbi13: " << bi13 << std::endl;
	std::cout << "bi13 <<= 3: " << (bi13 <<= 3) << std::endl;

	bigint bi14(3210123);
	std::cout << "\nbi14: " << bi14 << std::endl;
	std::cout << "bi14 >>= 3: " << (bi14 >>= 3) << std::endl;


	bigint bi5("000012345");
	std::cout << "\nbi5: " << bi5;

	if (bi5 == bi2)
		std::cout << "\nIguals" << std::endl;
	else
		std::cout << "NO Iguals" << std::endl;

	if (bi5 == bi1)
		std::cout << "Iguals" << std::endl;
	else
		std::cout << "NO Iguals" << std::endl;


	std::cout << std::endl;
	if (bi5 != bi2)
		std::cout << "Diffs." << std::endl;
	else
		std::cout << "NO Diffs." << std::endl;

	if (bi5 != bi1)
		std::cout << "Diffs." << std::endl;
	else
		std::cout << "NO Diffs." << std::endl;

	std::cout << std::endl;
	if (bi5 < bi2)
		std::cout << "Cert" << std::endl;
	else
		std::cout << "False" << std::endl;

	if (bi5 < bi1)
		std::cout << "Cert" << std::endl;
	else
		std::cout << "False" << std::endl;

	if (bi1 < bi5)
		std::cout << "Cert" << std::endl;
	else
		std::cout << "False" << std::endl;


	std::cout << std::endl;
	bigint bi6(12245);
	bigint bi7(12445);
	std::cout << bi6 << "<=" << bi7 << std::endl;
	if (bi5 <= bi2)
		std::cout << "Cert" << std::endl;
	else
		std::cout << "False" << std::endl;

	std::cout << bi5 << "<=" << bi6 << std::endl;
	if (bi5 <= bi6)
		std::cout << "Cert" << std::endl;
	else
		std::cout << "False" << std::endl;

	std::cout << bi5 << "<=" << bi7 << std::endl;
	if (bi5 <= bi7)
		std::cout << "Cert" << std::endl;
	else
		std::cout << "False" << std::endl;

	std::cout << std::endl;
	bigint bi8(12345);
	bigint bi9(97890);
	bigint bi10 = bi8 + bi9;
	std::cout << "\nbi10: " << bi10;
	bigint bi11 = bi9 + bi8;
	std::cout << "\nbi11: " << bi11;

	bigint bi12 = bi10 + bi11;
	std::cout << "\nbi12: " << bi12;

	bi1 += bi10;
	std::cout << "\nbi1: " << bi1;

	std::cout << std::endl;

	return (0);
}