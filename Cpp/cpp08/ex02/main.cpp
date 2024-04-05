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

	std::cout << std::endl << "----- Testing from the subject -----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl; mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
	++it; }
	std::stack<int> s(mstack);

	return 0;
}
