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

	std::cout << std::endl;
	std::cout << "---------Deep Copy proof----------" << std::endl;
	std::cout << std::endl;

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
