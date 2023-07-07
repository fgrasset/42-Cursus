#include "Zombie.hpp"

/* creates zombie and makes it announce himself */
void	randomChump(std::string name)
{
	Zombie zomb;

	zomb.addName(name);
	zomb.announce();
}
