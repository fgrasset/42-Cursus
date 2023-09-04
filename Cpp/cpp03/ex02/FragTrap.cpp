#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name, 100, 100, 30)
{
	std::cout << "Name constructor FragTrap called for " << Name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor FragTrap called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::string	input;

	std::cout << "Do you want a High Five ? (Y/N): ";
	std::cin >> input;
	if (input == "Y")
		std::cout << "RRGWWWRGRGRGWWGW, friends !!!" << std::endl;
	else if (input == "N")
		std::cout << "RRWWWHWHWHWR you bad human !" << std::endl;
	else
		std::cout << "WWWRGWHRRRW ?" << std::endl;
	this->_Energy--;
}
