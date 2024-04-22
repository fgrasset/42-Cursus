#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &src)
{
	this->_stack = src._stack;
}

RPN::~RPN()
{

}

RPN		&RPN::operator=(const RPN &src)
{
	if (this != &src)
		this->_stack = src._stack;

	return *this;
}

void	RPN::calculate(std::string input)
{
	int		strLen = input.size();;
	if ((strLen < 2) || !isdigit(input[0]))
		throw std::invalid_argument("Wrong input please use single digits and (+-*/) operators");
	for (int i = 0; i < strLen; i++)
	{
		if (isWhiteSpace(i, input[i]))
			continue;
		if (std::isdigit(input[i]))
		{
			this->_stack.push(input[i] - '0');
		}
		else if (isOperator(input[i]))
		{
			this->_stack.push(toPop(input[i]));
		}
		else
		{
			throw std::invalid_argument("Wrong input please use single digits and (+-*/) operators");
		}
	}
	if (this->_stack.size() > 1)
		throw std::invalid_argument("Wrong input please use single digits and (+-*/) operators");
	else if (this->_stack.size() == 0)
		throw std::invalid_argument("Wrong input please use single digits and (+-*/) operators");
	long	result = this->_stack.top();
	std::cout << result << std::endl;
}

long	RPN::toPop(char ops)
{
	if (this->_stack.size() <= 1)
		throw std::invalid_argument("Wrong input please use single digits and (+-*/) operators");
	long	a = this->_stack.top();
	this->_stack.pop();
	long	b = this->_stack.top();
	this->_stack.pop();

	switch (ops)
	{
		case '+':
			return (a + b);
		case '-':
			return (b - a);
		case '*':
			return (a * b);
		case '/':
			if (a == 0)
				throw std::invalid_argument("Cannot divide by 0");
			return (b / a);
		default:
			throw std::invalid_argument("Invalid operator");
	}
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;

	return false;
}

bool	RPN::isWhiteSpace(int i, char c)
{
	if (((i % 2) != 0) && (c == ' '))
	{
		return true;
	} else if ((i % 2) == 0) {
		return false;
	} else {
		throw std::invalid_argument("Wrong input please use single digits and (+-*/) operators");
	}
}
