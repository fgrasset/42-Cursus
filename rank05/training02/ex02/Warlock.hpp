#pragma once

#include <iostream>
#include "SpellBook.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	std::string name;
	std::string title;
	SpellBook	book;
	Warlock();
	Warlock(const Warlock &src);
	Warlock	&operator=(const Warlock &src);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		std::string	const &getName() const;
		std::string const &getTitle() const;
		void	setTitle(std::string const &title);
		void	introduce() const;

		void	learnSpell(ASpell *spellPtr);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, ATarget const &target);
};
