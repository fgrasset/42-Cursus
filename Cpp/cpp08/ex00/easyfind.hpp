#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "There is no occurence of this number in the container";
		}
};

template<typename T>
void	easyfind(T &container, int n)
{
	typename	T::iterator it = container.begin();
	typename	T::iterator ite = container.end();
	typename	T::iterator index = std::find(it, ite, n);

	if (index != ite)
	{
		std::cout << "First occurence of " << n << " is at index " << std::distance(it, index) << std::endl;
	}
	else
	{
		throw NException();
	}
}

#endif
