#pragma once

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook
{
	std::map<std::string, ASpell *>	arr_spell;
	SpellBook(const SpellBook &src);
	SpellBook	&operator=(const SpellBook &src);

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *spellPtr);
		void	forgetSpell(std::string const &spellName);
		ASpell	*createSpell(std::string const &spellName);
};
