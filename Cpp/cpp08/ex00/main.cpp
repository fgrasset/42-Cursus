#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
	std::cout << "----- Testing with a vector (10, 2, 5, 2, 8) -----" << std::endl;
	std::vector<int> vectorTest;
	vectorTest.push_back(10);
	vectorTest.push_back(2);
	vectorTest.push_back(5);
	vectorTest.push_back(2);
	vectorTest.push_back(8);

	std::cout << "easyfind() with 5 and 15" << std::endl;
	try {
		easyfind(vectorTest, 5);
		easyfind(vectorTest, 15);
	} catch (const NException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "----- Testing with a list (3, 7, 3, 9) -----" << std::endl;
	std::list<int> listTest;
	listTest.push_back(3);
	listTest.push_back(7);
	listTest.push_back(3);
	listTest.push_back(9);

	std::cout << "easyfind() with 3 and 42" << std::endl;
	try {
		easyfind(listTest, 3);
		easyfind(listTest, 42);
	} catch (const NException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
