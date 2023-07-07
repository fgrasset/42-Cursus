#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	Weapon		*_weapon;
	std::string	_name;
public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon weapon);
	void	attack(void);
};

#endif
