#pragma once

#include <iostream>

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string	effects;

	public:
		ASpell();
		ASpell(std::string const &name, std::string const &effects);
		ASpell(const ASpell &src);
		virtual ~ASpell();

		ASpell	&operator=(const ASpell &src);

		std::string const	&getName() const;
		std::string const	&getEffects() const;
		virtual ASpell	*clone() const = 0;

		void	launch(ATarget const &target_ref) const;
};

#include "ATarget.hpp"
