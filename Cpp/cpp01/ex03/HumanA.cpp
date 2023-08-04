#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

/* setts the weapon */
void	HumanA::setWeapon(Weapon weapon)
{
	_weapon = weapon;
}

/* Human attacks */
void	HumanA::attack(void)
{
	std::cout << _name << " with their " << &_weapon << std::endl;
}
