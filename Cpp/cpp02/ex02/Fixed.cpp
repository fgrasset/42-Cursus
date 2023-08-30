#include "Fixed.hpp"

Fixed::Fixed() : _x(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int x)
{
	std::cout << "Parametric int constructor called" << std::endl;
	this->_x = x << this->_bit;
}

Fixed::Fixed(float x)
{
	std::cout << "Parametric float constructor called" << std::endl;
	this->_x = roundf(x * (1 << this->_bit));
}

Fixed::Fixed(Fixed const &src) : _x(src._x)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int				Fixed::getX(void) const
{
	return (_x);
}

float			Fixed::toFloat(void) const
{
	return (float)_x / (1 << _bit);
}

int				Fixed::toInt(void) const
{
	return _x >> _bit;
}

int				Fixed::operator>(Fixed const &x) const
{
	return (this->toFloat() > x.toFloat());
}

int				Fixed::operator<(Fixed const &x) const
{
	return (this->toFloat() < x.toFloat());
}

int				Fixed::operator>=(Fixed const &x) const
{
	return (this->toFloat() >= x.toFloat());
}

int				Fixed::operator<=(Fixed const &x) const
{
	return (this->toFloat() <= x.toFloat());
}

int				Fixed::operator==(Fixed const &x) const
{
	return (this->toFloat() == x.toFloat());
}

int				Fixed::operator!=(Fixed const &x) const
{
	return (this->toFloat() != x.toFloat());
}

Fixed			Fixed::operator+(Fixed const &x) const
{
	return (this->toFloat() + x.toFloat());
}

Fixed			Fixed::operator-(Fixed const &x) const
{
	return (this->toFloat() - x.toFloat());
}

Fixed			Fixed::operator*(Fixed const &x) const
{
	return (this->toFloat() * x.toFloat());
}

Fixed			Fixed::operator/(Fixed const &x) const
{
	return (this->toFloat() / x.toFloat());
}

Fixed			&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed			Fixed::operator--(int)
{
	Fixed a = (*this);
	this->setRawBits(this->getRawBits() - 1);
	return a;
}

Fixed			&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed a = (*this);
	this->setRawBits(this->getRawBits() + 1);
	return a;
}

Fixed			&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const		&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed			&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const		&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

int				Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_x);
}

void			Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_x = raw;
}
