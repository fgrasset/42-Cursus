#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), sound("Woof Woof")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << this->sound << std::endl;
}
