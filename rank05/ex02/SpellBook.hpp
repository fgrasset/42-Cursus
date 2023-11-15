#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
	std::map<std::string, ASpell *> arr_spell;

	SpellBook(const SpellBook &src);
	SpellBook	&operator=(const SpellBook &src);

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &spell_name);
		ASpell	*createSpell(std::string const &spell_name);
};
