#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}

/* returns the value _type */
std::string	&Weapon::getType(void)
{
	std::string	&type = _type;
	return (type);
}

/* sets the new given value to _type */
void	Weapon::setType(std::string newType)
{
	_type = newType;
}
