#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src)
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
	return *this;
}

AMateria	*Cure::clone() const
{

}

void		Cure::use(ICharacter &target)
{

}
