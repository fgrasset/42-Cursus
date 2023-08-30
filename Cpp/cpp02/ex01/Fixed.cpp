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

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}
