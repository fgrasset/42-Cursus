#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout << "Cure copy constrcuctor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure		&Cure::operator=(const Cure &src)
{
	if (&src == this)
		return *this;
	AMateria::operator=(src);
	return *this;
}

AMateria	*Cure::clone() const
{
	return new Cure(*this);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
