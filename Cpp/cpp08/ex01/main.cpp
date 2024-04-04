#include "Span.hpp"

int main() {
	std::cout << "----- Testing basic span usage -----" << std::endl;
	Span sp(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.print();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const Span::FullSpan &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	} catch (const Span::UnfindeableElement& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "----- Testing to use the function fill() to add elements -----" << std::endl;
	std::vector<int>  numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	Span sp2(6);
	std::cout << "Now using fill()..." << std::endl;
	try {
		sp2.fill(numbers.begin(), numbers.end(), 5);
		sp2.print();
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	} catch (const Span::FullSpan &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "----- Testing to add above the capacity -----" << std::endl;

	try {
		sp.print();
		sp.addNumber(2);
	} catch (const Span::FullSpan &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "----- Testing with 10000 elements -----" << std::endl;
	for (int i = 0; i < 10001; i++)
	{
		numbers.push_back(i);
	}

	Span sp3(12000);

	try {
		sp3.fill(numbers.begin(), numbers.end(), 0);
		sp3.print();
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	} catch (const Span::FullSpan &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}
