#ifndef SWAP_HPP
# define SWAP_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T T_temp = b;
	a = b;
	b = T_temp;
}

#endif
