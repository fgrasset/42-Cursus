#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	std::string	sound;
	Brain		*_brain;

	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog		&operator=(const Dog &other);
		void	makeSound() const;
		Brain	*getBrain() const;
};

#endif
