#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zomb = newZombie("Paul");

	zomb->announce();
	delete zomb;
	randomChump("Georges");
}
