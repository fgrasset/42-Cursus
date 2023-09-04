#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal	*base = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	base->makeSound();

	delete base;
	delete dog;
	delete cat;

	std::cout << "--- Failure Tests ---" << std::endl;
	const WrongAnimal	*wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	delete wrongCat;
}
