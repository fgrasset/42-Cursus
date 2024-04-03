#include "Span.hpp"

int main() {
	// Test 1: Basic usage and span calculation
	Span sp(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const Span::FullSpan& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	} catch (const Span::UnfindeableElement& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	 // Test 2: Filling with iterator range - C++98 Style
	std::vector<int>  numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	Span sp2(6);

	try {
		sp2.fill(numbers.begin(), numbers.end(), 5);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const Span::FullSpan& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Trying to add beyond capacity
	try {
		sp.addNumber(2);
	} catch (const Span::FullSpan& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
