#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *zomb = new Zombie;
	zomb->addName(name);
	return (zomb);
}
