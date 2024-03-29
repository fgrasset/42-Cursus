#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array<unsigned int, T>
{


	public:
		Array<T>();
		Array<T>(const Array &src);
		~Array<T>();

		Array	&operator=(const Array &src);

};

#endif
