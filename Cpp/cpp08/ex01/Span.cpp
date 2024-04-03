#include "Span.hpp"

Span::Span(unsigned int N) : _max(N)
{

}

Span::Span(const Span &src)
{
	this->_max = src._max;
	this->_container = src._container;
}

Span::~Span()
{

}

Span	&Span::operator=(const Span &src)
{
	this->_max = src._max;
	this->_container = src._container;
	return *this;
}

void	Span::addNumber(int nb)
{
	if (this->_container.size() <= this->_max)
		this->_container.push_back(nb);
	else
		throw FullSpan();
}

int		Span::shortestSpan()
{
	std::vector<int>::iterator	min = std::min_element(this->_container.begin(), this->_container.end());
	if (min != this->_container.end())
		return (*min);
	else
		throw UnfindeableElement();
}

int		Span::longestSpan()
{
	std::vector<int>::iterator	max = std::max_element(this->_container.begin(), this->_container.end());
	if (max != this->_container.end())
		return (*max);
	else
		throw UnfindeableElement();
}

void	Span::fill(std::vector<int>::iterator it, std::vector<int>::iterator ite, int number)
{
	if ((this->_container.size() + std::distance(it, ite)) > this->_max)
		throw FullSpan();
	for (; it != ite; ++it)
		this->_container.push_back(*it + number);
}
