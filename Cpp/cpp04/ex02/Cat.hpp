#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	std::string	sound;
	Brain		*_brain;

	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		void	makeSound() const;
		Brain	*getBrain() const;
};

#endif
