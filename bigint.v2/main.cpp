#include "bigint.hpp"

int main()
{
	bigint bi1;
	bigint bi2("0000123");
	bigint bi3(456);
	bigint bi4 = bi3;
	bigint bi5(bi4);

	std::cout << "bi1: " << bi1 << std::endl;
	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi3: " << bi3 << std::endl;
	std::cout << "bi4: " << bi4 << std::endl;
	std::cout << "bi5: " << bi5 << std::endl;

	bigint bi6 = bi5 >> 0;
	std::cout << "bi6 = bi5 >> 0: " << bi6 << std::endl;

	bi6 = bi5 >> 1;
	std::cout << "bi6 = bi5 >> 1: " << bi6 << std::endl;

	bi6 = bi5 >> 3;
	std::cout << "bi6 = bi5 >> 3: " << bi6 << std::endl;

	bi6 = bi5 >> 4;
	std::cout << "bi6 = bi5 >> 4: " << bi6 << std::endl;


	bi6 = bi5 << 0;
	std::cout << "bi6 = bi5 << 0: " << bi6 << std::endl;

	bi6 = bi5 << 1;
	std::cout << "bi6 = bi5 << 1: " << bi6 << std::endl;

	bi6 = bi5 << 3;
	std::cout << "bi6 = bi5 << 3: " << bi6 << std::endl;

	bi6 = bi5 << 4;
	std::cout << "bi6 = bi5 << 4: " << bi6 << std::endl;

	bi6 >>= 4;
	std::cout << "bi6 >>= 4: " << bi6 << std::endl;

	bi6 <<= 4;
	std::cout << "bi6 <<= 4: " << bi6 << std::endl;

	bigint bi7(12345);
	std::cout << "bi7: " << bi7 << std::endl;
	std::cout << "bi7 <<= 5: " << (bi7 <<= 5) << std::endl;
	std::cout << "bi7 >>= 5: " << (bi7 >>= 5) << std::endl;

	std::cout << std::endl;
	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi3: " << bi3 << std::endl;
	std::cout << "bi4: " << bi4 << std::endl;
	std::cout << "bi2 == bi3: " << (bi2 == bi3) << std::endl;
	std::cout << "bi2 == bi4: " << (bi2 == bi4) << std::endl;
	std::cout << "bi3 == bi4: " << (bi3 == bi4) << std::endl;
	std::cout << "bi2 != bi3: " << (bi2 != bi3) << std::endl;
	std::cout << "bi2 != bi4: " << (bi2 != bi4) << std::endl;
	std::cout << "bi3 != bi4: " << (bi3 != bi4) << std::endl;

	std::cout << std::endl;
	std::cout << "bi1: " << bi1 << std::endl;
	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi3: " << bi3 << std::endl;
	std::cout << "bi4: " << bi4 << std::endl;
	std::cout << "bi5: " << bi5 << std::endl;
	std::cout << "bi6: " << bi6 << std::endl;
	std::cout << "bi2 < bi3: " << (bi2 < bi3) << std::endl;
	std::cout << "bi6 < bi4: " << (bi6 < bi4) << std::endl;
	std::cout << "bi3 < bi4: " << (bi3 < bi4) << std::endl;
	std::cout << "bi1 > bi3: " << (bi1 > bi3) << std::endl;
	std::cout << "bi2 > bi4: " << (bi2 > bi4) << std::endl;
	std::cout << "bi3 > bi4: " << (bi3 > bi4) << std::endl;

	std::cout << std::endl;
	std::cout << "bi1: " << bi1 << std::endl;
	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi3: " << bi3 << std::endl;
	std::cout << "bi4: " << bi4 << std::endl;
	std::cout << "bi1 <= bi3: " << (bi1 <= bi3) << std::endl;
	std::cout << "bi2 <= bi4: " << (bi6 <= bi4) << std::endl;
	std::cout << "bi3 <= bi4: " << (bi3 <= bi4) << std::endl;
	std::cout << "bi1 >= bi3: " << (bi1 >= bi3) << std::endl;
	std::cout << "bi2 >= bi4: " << (bi2 >= bi4) << std::endl;
	std::cout << "bi3 >= bi4: " << (bi3 >= bi4) << std::endl;

	std::cout << std::endl;
	bigint bi8(67890);
	bigint bi9(97890);
	bigint bi10(0);
	bigint bi11(0);
	bigint bi12(0);
	bigint bi13(0);
	bigint bi14(0);
	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi7: " << bi7 << std::endl;
	std::cout << "bi8: " << bi8 << std::endl;
	std::cout << "bi9: " << bi9 << std::endl;
	std::cout << "bi10 = bi7 + bi8: " << (bi10 = bi7 + bi8) << std::endl << std::endl;
	std::cout << "bi11 = bi9 + bi7: " << (bi11 = bi9 + bi7) << std::endl << std::endl;
	std::cout << "bi14 = bi7 + bi9: " << (bi14 = bi7 + bi9) << std::endl << std::endl;
	std::cout << "bi12 = bi7 + bi2: " << (bi12 = bi7 + bi2) << std::endl << std::endl;
	std::cout << "bi13 = bi2 + bi7: " << (bi13 = bi2 + bi7) << std::endl << std::endl;

	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi7: " << bi7 << std::endl;
	std::cout << "bi2 += bi7: " << (bi2 += bi7) << std::endl;
	std::cout << "bi2: " << bi2 << std::endl;
	std::cout << "bi7: " << bi7 << std::endl;


	return (0);
}