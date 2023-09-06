#ifndef CURE_HPP
# define CURE_HPP

#include "Materia.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		~Cure();

		Cure	&operator=(const Cure &src);
		AMateria	*clone() const = 0;
		void		use(ICharacter &target);
};

#endif
