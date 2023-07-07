#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB()
{
}

/* sets the weapon */
void	HumanB::setWeapon(Weapon weapon)
{
	*_weapon = weapon;
}

/* human attack */
void	HumanB::attack(void)
{
	std::cout << _name << " with their " << _weapon << std::endl;
}
