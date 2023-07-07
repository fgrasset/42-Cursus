#include "Zombie.hpp"

/* creates and returns a horde of zombies of size N */
Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		horde[i].addName(name);
	}
	return (horde);
}
