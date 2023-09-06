#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Materia.hpp"
class Character : public ICharacter
{
	public:
		Character();
		Character(const Character &src);
		~Character();

		Character	&operator=(const Character &src);
};

#endif
