#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
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
	AMateria::operator=(src);
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice(*this);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
