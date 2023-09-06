#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter&src)
{
	std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructor called" << std::endl;
}

ICharacter		&ICharacter::operator=(const ICharacter &src)
{

}


