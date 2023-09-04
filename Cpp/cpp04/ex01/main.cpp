#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	int				nb = 20;
	const Animal	*noe[nb];

	for (int i = 0; i < nb; i++)
	{
		if (i % 2 == 0)
			noe[i] = new Dog();
		else
			noe[i] = new Cat();
	}

	std::cout << noe[4]->getType() << " " << std::endl;
	noe[4]->makeSound();
	std::cout << noe[17]->getType() << " " << std::endl;
	noe[17]->makeSound();

	for (int i = 0; i < nb; i++)
	{
		delete noe[i];
	}
}
