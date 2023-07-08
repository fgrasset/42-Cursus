#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

/* sets the weapon */
void	HumanA::setWeapon(Weapon weapon)
{
	_weapon = weapon;
}

/* human attack */
void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
