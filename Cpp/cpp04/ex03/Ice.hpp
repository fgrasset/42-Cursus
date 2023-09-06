#ifndef ICE_HPP
# define ICE_HPP

#include "Materia.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &src);
		~Ice();

		Ice	&operator=(const Ice &src);
		AMateria	*clone() const = 0;
		void		use(ICharacter &target);
};

#endif
