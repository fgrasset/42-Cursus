#pragma once

#include <iostream>

class ATarget;

class ASpell
{
	std::string	_name;
	std::string	_effects;

	public:
		ASpell();
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();
		ASpell(const ASpell &src);

		ASpell	&operator=(const ASpell &src);
		std::string const	&getName() const;
		std::string const	&getEffects() const;

		void	launch(const ATarget &target) const;
};

#include "ATarget.hpp"
