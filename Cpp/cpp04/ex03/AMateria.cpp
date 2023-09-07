#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	this->type = src.type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &src)
{
	if (&src == this)
		return *this;
	this->type = src.type;
	return *this;
}

AMateria			*AMateria::clone() const
{
	return (0);
}

void				AMateria::use(ICharacter &target)
{
	(void) target;
}

std::string const	&AMateria::getType() const
{
	return this->type;
}
