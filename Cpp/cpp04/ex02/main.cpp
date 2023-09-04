#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	int				nb = 2;
	const Animal	*noe[nb];
	// const Animal	*animal = new Animal();			//Not working because it is an abstract class

	for (int i = 0; i < nb; i++)
	{
		if (i % 2 == 0)
			noe[i] = new Dog();
		else
			noe[i] = new Cat();
	}

	std::cout << noe[0]->getType() << " " << std::endl;
	noe[0]->makeSound();
	std::cout << noe[1]->getType() << " " << std::endl;
	noe[1]->makeSound();

	for (int i = 0; i < nb; i++)
	{
		delete noe[i];
	}
}
