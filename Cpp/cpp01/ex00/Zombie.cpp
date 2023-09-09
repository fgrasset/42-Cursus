#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "Destroying Zombie " << _name << std::endl;
}

/* adds the name of the zombie*/
void	Zombie::addName(std::string name)
{
	_name = name;
}

/* the zombie announces himself with his name first */
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
