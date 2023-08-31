#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	this->_Name = other._Name;
	this->_Hit = other._Hit;
	this->_Energy = other._Energy;
	this->_AD = other._AD;
	return *this;
}

void		ClapTrap::attack(const std::string &target)
{
	if (_Hit <= 0)
		std::cout << "Life has run out..." << std::endl;
	if (_Energy <= 0)
		std::cout << "Energy has run out..." << std::endl;

}

void		ClapTrap::takeDamage(unsigned int amount)
{
	this->_Hit - amount;
	std::cout << this->_Name << "took " << amount << " of damage, now that is scary :O" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{

}
