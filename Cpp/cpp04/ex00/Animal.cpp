#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal name constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}

void		Animal::makeSound() const
{
	std::cout << "Silence..." << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
