#include "iter.hpp"

int main()
{
	std::cout << "------Testing with integers------" << std::endl;
	int intArray[] = {1, 5, -3, 8};
	size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intArrayLen, print);

	std::cout << "------Testing with floats------" << std::endl;
	float	floatArray[] = {14.65f, 884.02f, -48.35f};
	size_t floatArrayLen = sizeof(floatArray) / sizeof(floatArray[0]);
	iter(floatArray, floatArrayLen, print);

	std::cout << "------Testing with strings------" << std::endl;
	std::string strArray[] = {"Hello", "World", "!"};
	size_t strArrayLen = sizeof(floatArray) / sizeof(floatArray[0]);
	iter(strArray, strArrayLen, print);

	return 0;
}
