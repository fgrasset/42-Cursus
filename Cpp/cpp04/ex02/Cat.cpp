#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), sound("Miaou")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy cosntructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (&other == this)
		return *this;
	Animal::operator=(other);
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << this->sound << std::endl;
}

Brain	*Cat::getBrain() const
{
	return this->_brain;
}
