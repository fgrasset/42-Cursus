#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	T				*_arr;
	unsigned int	_size;

	public:
		Array<T>();
		Array<T>(unsigned int size);
		Array<T>(const Array &src);
		~Array<T>();

		Array			&operator=(const Array &src);
		T				&operator[](unsigned const int i);
		unsigned int	getSize() const;


	class IndexOutOfBounds : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Index out of bounds");
			}
	};
};

#endif
