#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character : public ICharacter
{
	std::string const	_name;
	AMateria			*_inventory[4];
	AMateria			*_ground[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &src);
		~Character();

		Character	&operator=(const Character &src);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
