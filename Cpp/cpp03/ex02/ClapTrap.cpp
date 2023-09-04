#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Player"), _Hit(10), _Energy(10), _AD(0)
{
	std::cout << "Constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _Hit(10), _Energy(10), _AD(6)
{
	std::cout << "Name ClapTrap constructor called for " << Name << std::endl;
}

ClapTrap::ClapTrap(std::string Name, unsigned int Hit, unsigned int Energy, unsigned int AD) : _Name(Name), _Hit(Hit), _Energy(Energy), _AD(AD)
{
	std::cout << "Full ClapTrap constructor called for " << Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _Name(other._Name), _Hit(other._Hit), _Energy(other._Energy), _AD(other._AD)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap called" << std::endl;
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

std::string	ClapTrap::getName()
{
	return (this->_Name);
}

void		ClapTrap::attack(const std::string &target)
{
	if (this->_Hit <= 0)
		std::cout << "Life has run out..." << std::endl;
	if (this->_Energy <= 0)
		std::cout << this->_Name << " has run out of fuel... " << std::endl;
	this->_Energy--;
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << " , causing " << this->_AD << " points of damage !" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_Hit)
		amount = this->_Hit;
	this->_Hit = _Hit - amount;
	std::cout << this->_Name << " took " << amount << " points of damage, now that is scary :O" << std::endl;
}

void		ClapTrap::fight(ClapTrap &enemy)
{
	this->attack(enemy.getName());
	enemy.takeDamage(this->_AD);
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energy > 0 && this->_Hit > 0)
	{
		this->_Energy--;
		this->_Hit += amount;
		std::cout << this->_Name << " gained " << amount << " of health back... Well done !" << std::endl;
	}
	else
		std::cout << this->_Name << " has run out of fuel... " << std::endl;
}

void		ClapTrap::stats()
{
	std::cout << "Name: " << this->_Name << std::endl;
	std::cout << "Health: " << this->_Hit << std::endl;
	std::cout << "Energy: " << this->_Energy << std::endl;
	std::cout << "AD: " << this->_AD << std::endl;
}
