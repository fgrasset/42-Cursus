#ifndef MATERIA_HPP
# define MATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
	std::string	type;
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		~AMateria();
		AMateria	&operator=(const AMateria &src);

		std::string const 	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
