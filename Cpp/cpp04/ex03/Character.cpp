#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &src)
{
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

Character	&Character::operator=(const Character &src)
{
	if (&src == this)
		return *this;
	return *this;
}
