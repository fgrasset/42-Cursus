#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zomb;

	zomb.addName(name);
	zomb.announce();
}
