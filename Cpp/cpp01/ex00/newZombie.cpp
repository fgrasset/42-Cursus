#include "Zombie.hpp"

/* allocates memory for a new Zombie */
Zombie	*newZombie(std::string name)
{
	Zombie *zomb = new Zombie;
	zomb->addName(name);
	return (zomb);
}
