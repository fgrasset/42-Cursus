#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = nullptr;
		this->_ground[i] = nullptr;
	}
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = nullptr;
		this->_ground[i] = nullptr;
	}
}

Character::Character(const Character &src) : _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		delete this->_ground[i];
	}
}

Character			&Character::operator=(const Character &src)
{
	if (&src == this)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
	return *this;
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void				Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "* this element is not known to the player *" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if(!_inventory[i])
		{
			_inventory[i] = m;
			break;
		}
	}
	std::cout << "* " << this->getName() << " equipped " << m->getType() << " *" << std::endl;
}

void				Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && this->_inventory[idx])
	{
		for(int i = 0; i < 4; i++)
		{
			if (!this->_ground[i])
			{
				this->_ground[i] = this->_inventory[idx];
				this->_inventory[idx] = nullptr;
				std::cout << "* " << this->getName() << " unequipped " << this->_ground[i]->getType() << " *" << std::endl;
				return ;
			}
		}
		delete this->_ground[0];
		this->_ground[0] = this->_inventory[idx];
		this->_inventory[idx]= nullptr;
		std::cout << "* " << this->getName() << " unequipped " << this->_ground[0]->getType() << " *" << std::endl;
	}
	else
		std::cout << "* there is no equipement in the " << idx << " inventory slot *" << std::endl;

}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx] && _inventory[idx] != nullptr)
			_inventory[idx]->use(target);
		else
			std::cout << "* there is no equipement in the " << idx << " inventory slot *" << std::endl;
	}

}
