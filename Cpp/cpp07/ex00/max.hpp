#ifndef MAX_HPP
# define MAX_HPP

template <typename T1, typename T2>

void max(T1 &a, T2 &b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif