#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	T newArray = new T[];
}

template<typename T>
Array<T>::Array(const Array &src)
{
	new T[other.arraySize];
	for (unsigned int i = 0; i < arraySize; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
Array<T>::~Array()
{

}

template<typename T>
Array	&Array::operator=(const Array &src)
{

}


#endif
