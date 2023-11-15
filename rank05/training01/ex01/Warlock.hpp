#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

/* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.*/

class Warlock
{
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell *> arr;
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
