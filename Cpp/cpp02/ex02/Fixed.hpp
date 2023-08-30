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

	int				getX(void) const;
	float			toFloat(void) const;
	int				toInt(void) const;
	int				getRawBits(void) const;
	void			setRawBits(int const raw);

	int				operator>(Fixed const &x) const;
	int				operator<(Fixed const &x) const;
	int				operator>=(Fixed const &x) const;
	int				operator<=(Fixed const &x) const;
	int				operator==(Fixed const &x) const;
	int				operator!=(Fixed const &x) const;

	Fixed			operator+(Fixed const &x) const;
	Fixed			operator-(Fixed const &x) const;
	Fixed			operator*(Fixed const &x) const;
	Fixed			operator/(Fixed const &x) const;

	Fixed			&operator++(void);
	Fixed			operator++(int);
	Fixed			&operator--(void);
	Fixed			operator--(int);

	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

 #endif
