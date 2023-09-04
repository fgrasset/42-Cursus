#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), sound("Miaou")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy cosntructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << this->sound << std::endl;
}
