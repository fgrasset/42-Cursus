#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src)
{
	std::cout << "Ice copy constructr called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice		&Ice::operator=(const Ice &src)
{
	if (&src == this)
		return *this;
	return *this;
}

AMateria	*Ice::clone() const
{

}

void		Ice::use(ICharacter &target)
{

}
