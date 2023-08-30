#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class	Fixed
{
	int					_x;
	static const int	_bit = 8;
public:
	Fixed();
	Fixed(int _x);
	Fixed(float x);
	Fixed(Fixed const &src);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		getX(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

 #endif
