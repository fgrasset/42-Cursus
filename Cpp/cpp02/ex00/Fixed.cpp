#include "Fixed.hpp"

Fixed::Fixed() : _x(0)
{
	std::cout << "Constructor called" << std::endl;
}

Fixed::Fixed(int x) : _x(x)
{
	std::cout << "Parametric constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_x = src.getRawBits();

	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	if (this != &src)
		this->_x = src.getRawBits();
	return *this;
}


int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_x);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_x = raw;
}
