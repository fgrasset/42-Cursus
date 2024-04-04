#include <stack>
#include <iostream>
#include "MutantStack.hpp"

int main() {
	std::cout << "----- Testing with integers ------" << std::endl;
	MutantStack<int> intStack;
	intStack.push(10);
	intStack.push(3);
	intStack.push(89);
	for (MutantStack<int>::iterator it = intStack.begin(); it != intStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl << "----- Testing with doubles ------" << std::endl;
	MutantStack<double> doubleStack;
	doubleStack.push(3.14);
	doubleStack.push(2.718);
	for (MutantStack<double>::iterator it = doubleStack.begin(); it != doubleStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl << "----- Testing with strings ------" << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("hello");
	stringStack.push("world");
	for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}
