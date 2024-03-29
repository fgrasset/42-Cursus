#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	T				*_arr;
	unsigned int	_size;

	public:
		Array<T>();
		Array<T>(unsigned int size);
		Array<T>(const Array &src);
		~Array<T>();

		Array<T>		&operator=(const Array &src);
		T				&operator[](unsigned const int i);
		unsigned int	size() const;


	class IndexOutOfBounds : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Index out of bounds");
			}
	};
};

template <typename T>
Array<T>::Array()
{
	this->_arr = nullptr;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	this->_arr = new T[this->_size];
}

template <typename T>
Array<T>::Array(const Array &src)
{
	this->_size = src._size;
	this->_arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_arr[i] = src._arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->_arr)
		delete[] this->_arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &src)
{
	if (this->_arr)
		delete[] this->_arr;
	this->_size = src._size;
	this->_arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_arr[i] = src._arr[i];
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
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

#endif
