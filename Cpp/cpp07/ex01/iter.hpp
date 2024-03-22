#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *arr, size_t len, void (*print)(T &))
{
	for (size_t i = 0; i < len; i++)
	{
		print(arr[i]);
	}
}

template <typename T>
void	print(T &element)
{
	std::cout << element << std::endl;
	return ;
}

#endif
