#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

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

	Dog	dog;
	Dog	copy_dog;

	dog.getBrain()->setIdea(0, "Main Dog Idea");
	copy_dog = dog;
	std::cout << "Main dog Idea: " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog Idea: " << copy_dog.getBrain()->getIdea(0) << std::endl;

	copy_dog.getBrain()->setIdea(0, "Fake Dog Idea");
	std::cout << "Main dog Idea: " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog Idea: " << copy_dog.getBrain()->getIdea(0) << std::endl;

}
