#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_arr = nullptr;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	this->arr = new T[this->_size];
}

template <typename T>
Array<T>::Array(const Array &src)
{
	this->_size = src->_size;
	this->_arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_arr[i] = src->_arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->_arr)
		delete[] this->_arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &src)
{
	if (this->_arr)
		delete[] this->_arr;
	this->_size = src->_size;
	this->_arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_arr[i] = src->_arr[i];
	}
	return *this;
}

template <typename T>
T	&Array<T>::operator[](unsigned const int i)
{
	if (i < 0 || i >= this->_size)
		throw IndexOutOfBounds();
	return (this->_arr[i]);
}

template <typename T>
unsigned int	Array<T>::getSize() const
{
	return (this->_size);
}

#endif
