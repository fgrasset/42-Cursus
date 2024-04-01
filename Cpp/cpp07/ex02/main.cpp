#include "Array.hpp"

int main() {
	try{
		std::cout << "----- Testing empty array -----" << std::endl;
		Array<int>	testEmpty;
		std::cout << "Size of the empty array: " << testEmpty.size() << std::endl;
	} catch (const Array<int>::IndexOutOfBounds& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try{
		std::cout << std::endl << "----- Testing floats -----" << std::endl;
		Array<float>	testFloat(3);
		testFloat[0] = 0.067;
		testFloat[1] = -24.56;
		testFloat[2] = 1002.13;
		std::cout << "Size of testFloat: " << testFloat.size() << std::endl;
		std::cout << "Printing the array: " << std::endl;
		for (unsigned int i = 0; i < testFloat.size(); i++)
		{
			std::cout << "testFloat[" << i << "] = " << testFloat[i] << std::endl;
		}
	} catch (const Array<int>::IndexOutOfBounds& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try{
		std::cout << std::endl << "----- Testing OutOfBOunds exception -----" << std::endl;
		Array<int>	testException(2);
		testException[0] = 2;
		testException[1] = -5;
		std::cout << "Size of the array: " << testException.size() << std::endl;
		std::cout << "Trying to acces third element" << std::endl;
		testException[2] = 42;
	} catch (const Array<int>::IndexOutOfBounds& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try{
		std::cout << std::endl << "----- Testing for = operator -----" <<std::endl;
		Array<std::string>	testOps(3);
		testOps[0] = "haha";
		testOps[1] = "wouhou";
		testOps[2] = "hihihi";
		std::cout << "Size of the array: " << testOps.size() << std::endl;
		std::cout << "Here is what's in the array: " << testOps[0] << ", " << testOps[1] << ", " << testOps[2] << std::endl;

		Array<std::string>	testOpsCpy(3);
		testOpsCpy = testOps;
		std::cout << "Here is what's in the copy array: " << testOpsCpy[0] << ", " << testOpsCpy[1] << ", " << testOpsCpy[2] << std::endl;
		testOps[2] = "wtf";
		std::cout << "Changing element testOpsCpy[2]: testOps[2]=" << testOps[2] << " vs testOpsCpy[2]=" << testOpsCpy[2] << std::endl;
	} catch (const Array<int>::IndexOutOfBounds& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
