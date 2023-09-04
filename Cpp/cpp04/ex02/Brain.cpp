#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i <= 100; i++)
	{
		_ideas[i] = src._ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &src)
{
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; ++i)
	{
		_ideas[i] = src._ideas[i];
	}
	return *this;
}

