#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::list<int> unsortedList, std::deque<int> unsortedDeque) : _list(unsortedList), _deque(unsortedDeque)
{
	std::cout << "Before: ";
	this->display();
	// sleep(1);

	clock_t	startDeque = clock();
	fordJohnsonSort(unsortedDeque);
	clock_t	endDeque = clock();

	clock_t	startList = clock();
	fordJohnsonSort(unsortedList);
	clock_t	endList = clock();

	std::cout << "After: ";
	this->display();
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list<int>: " << static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000 << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque<int>: " << static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000 << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe	&PmergeMe::operator=(const PmergeMe &src)
{
	this->_list = src._list;
	this->_deque = src._deque;

	return *this;
}


// Function to pair elements, extract larger ones, and sort them recursively
void	PmergeMe::sortDescending(std::list<int> &inputList, std::list<int> &sortedSubList)
{
	if (inputList.size() <= 1)
		return; // Base case for recursion

	std::list<int>::iterator	it1 = inputList.begin();
	std::list<int>::iterator	it2 = std::next(it1);

	while (it2 != inputList.end())
	{
		if (*it1 > *it2) {
			sortedSubList.push_back(*it1);
		} else {
			sortedSubList.push_back(*it2);
		}
		it1 = std::next(it2, 2); // Advance two positions
		it2 = std::next(it1, 2);
	}

	if (it1 != inputList.end()) { // Handle unpaired element
		sortedSubList.push_back(*it1);
	}

	sortDescending(sortedSubList, sortedSubList); // Recursion
}

void	PmergeMe::sortDescending(std::deque<int> &inputDeque, std::deque<int> &sortedSubDeque)
{
	if (inputDeque.size() <= 1)
		return; // Base case for recursion

	std::deque<int>::iterator	it1 = inputDeque.begin();
	std::deque<int>::iterator	it2 = std::next(it1);

	while ((it2 != inputDeque.end()))
	{
		if (*it1 > *it2) {
			sortedSubDeque.push_back(*it1);
		} else {
			sortedSubDeque.push_back(*it2);
		}
		std::cout << "test: " << *it1 << " and " << *it2 << std::endl;
		it1 = std::next(it2, 2); // Advance two positions
		it2 = std::next(it1, 2);
	}

	std::cout << "test" << std::endl;
	if (it1 != inputDeque.end()) { // Handle unpaired element
		sortedSubDeque.push_back(*it1);
	}

	sortDescending(sortedSubDeque, sortedSubDeque); // Recursion
}


// Binary-search like insertion
void	PmergeMe::insertElement(std::list<int> &sortedSubList, int element)
{
	std::list<int>::iterator low = sortedSubList.begin();
	std::list<int>::iterator high = sortedSubList.end();

	while (low != high) {
		std::list<int>::iterator mid = std::next(low, std::distance(low, high) / 2);
		if (element > *mid) {
			high = mid;
		} else {
			low = std::next(mid);
		}
	}
	sortedSubList.insert(low, element);
}

void	PmergeMe::insertElement(std::deque<int> &sortedSubDeque, int element)
{
	std::deque<int>::iterator low = sortedSubDeque.begin();
	std::deque<int>::iterator high = sortedSubDeque.end();

	while (low != high) {
		std::deque<int>::iterator mid = std::next(low, std::distance(low, high) / 2);
		if (element > *mid) {
			high = mid;
		} else {
			low = std::next(mid);
		}
	}
	sortedSubDeque.insert(low, element);
}


// Main Ford-Johnson sorting function
void	PmergeMe::fordJohnsonSort(std::list<int> &inputList)
{
	if (inputList.size() <= 1) return; // Already sorted

	std::list<int> sortedSubList;

	// Pairing and extracting larger elements
	sortDescending(inputList, sortedSubList);

	// Inserting remaining elements
	for (std::list<int>::iterator it = inputList.begin(); it != inputList.end(); ++it) {
		if (sortedSubList.empty() || *it >= sortedSubList.front()) {
			sortedSubList.push_front(*it);
		} else {
			insertElement(sortedSubList, *it);
		}
	}

	inputList = sortedSubList; // Copy back to the original list
}

void	PmergeMe::fordJohnsonSort(std::deque<int> &inputDeque)
{
	if (inputDeque.size() <= 1) return; // Already sorted

	std::deque<int> sortedSubDeque;

	// Pairing and extracting larger elements
	sortDescending(inputDeque, sortedSubDeque);

	// Inserting remaining elements
	for (std::deque<int>::iterator it = inputDeque.begin(); it != inputDeque.end(); ++it) {
		if (sortedSubDeque.empty() || *it >= sortedSubDeque.front()) {
			sortedSubDeque.push_front(*it);
		} else {
			insertElement(sortedSubDeque, *it);
		}
	}

	inputDeque = sortedSubDeque; // Copy back to the original list
}

void	PmergeMe::display()
{
	int	sizeDeque = this->_deque.size();
	for (int i =  0; i < sizeDeque; ++i)
	{
		std::cout << this->_deque[i] << " ";
	}
	std::cout << std::endl;
}
