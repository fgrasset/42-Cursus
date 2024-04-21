#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>

class RPN
{
	std::stack<long>	_stack;

	public:
		RPN();
		RPN(const RPN &src);
		~RPN();

		RPN		&operator=(const RPN &src);
		void	calculate(std::string input);
		long	toPop(char ops);
		bool	isOperator(char c);
		bool	isWhiteSpace(int i, char c);
};

#endif
