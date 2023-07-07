#include "Zombie.hpp"

int	main(void)
{
	int	size = 10;
	if (size < 0)
		return (0);
	Zombie *horde = zombieHorde(size, "Paul");

	for (int i = 0; i < size; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}
