#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	unsigned int		_max;
	std::vector<int>	_container;

	public:
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span	&operator=(const Span &src);
		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();
		void	fill(std::vector<int>::iterator it, std::vector<int>::iterator ite, int number);
		void	print();

	class FullSpan : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Span is full");
			}
	};

	class UnfindeableElement : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Can not find this element");
			}
	};
};

#endif
