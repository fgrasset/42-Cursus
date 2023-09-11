#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
class Fixed
{
	int					_x;
	static int const	_bit = 8;
public:
	Fixed();
	Fixed(int _x);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator=(Fixed const &src);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

 #endif
