#include "PmergeMe.hpp"

int main()
{
	std::deque<int> data = {8, 3, 11, 1, 5, 9, 2};
	std::list<int> inputList(data.begin(), data.end());

	// fordJohnsonSort(inputList);

	// Print the sorted list
	for (int num : inputList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}
