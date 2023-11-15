#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	std::string	_name;
	std::string	_title;
	SpellBook	book;
	Warlock();
	Warlock(const Warlock &src);
	Warlock	&operator=(const Warlock &src);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const	&getName() const;
		std::string const	&getTitle() const;
		void				setTitle(std::string const &title);
		void				introduce() const;

		void				learnSpell(ASpell *spell);
		void				forgetSpell(std::string spell_name);
		void				launchSpell(std::string spell_name, ATarget const &target);
};
