#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name, 100, 50, 20)
{
	std::cout << "Full ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << this->_Name << " entered Gate Keeper mode... YOU SHALL NOT PASS !" << std::endl;
}
