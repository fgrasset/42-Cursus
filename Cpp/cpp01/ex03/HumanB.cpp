#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB()
{
}

/* sets the weapon */
void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

/* human attack */
void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " is armless" << std::endl;
}
