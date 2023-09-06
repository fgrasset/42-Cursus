#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>
#include "Materia.hpp"

class ICharacter
{
	public:
		ICharacter();
		ICharacter(const ICharacter &src);
		virtual ~ICharacter() {}

		ICharacter	&operator=(const ICharacter &src);
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
