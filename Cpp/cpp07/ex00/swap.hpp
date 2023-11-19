#ifndef SWAP_HPP
# define SWAP_HPP

template <typename T1, typename T2>
void	swap(T1 &a, T2 &b)
{
	T2 T_temp = b;
	a = b;
	b = T_temp;
}

#endif
