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
	if (this->_container.size() < this->_max)
		this->_container.push_back(nb);
	else
		throw FullSpan();
}

int		Span::shortestSpan()
{
	if (this->_container.size() < 2)
		throw UnfindeableElement();
	std::sort(this->_container.begin(), this->_container.end());
	int	span = *std::next(this->_container.begin()) - this->_container.front();
	int	container_size = this->_container.size();
	for (int i = 1; i < container_size; i++)
	{
		int	dist = this->_container[i] - this->_container[i - 1];
		if (dist < span)
			span = dist;
	}
	return (span);
}

int		Span::longestSpan()
{
	if (this->_container.size() < 2)
		throw UnfindeableElement();
	std::sort(this->_container.begin(), this->_container.end());
	return (this->_container.back() - this->_container.front());
}

void	Span::fill(std::vector<int>::iterator it, std::vector<int>::iterator ite, int number)
{
	if ((this->_container.size() + std::distance(it, ite)) > this->_max)
		throw FullSpan();
	for (; it != ite; ++it)
		this->_container.push_back(*it + number);
}

void	Span::print()
{
	std::vector<int>::iterator	it = this->_container.begin();
	std::vector<int>::iterator	ite = this->_container.end() - 1;
	std::cout << "Vector {";
	for (; it < ite; ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << *it;
	std::cout << "}" << std::endl;
}
