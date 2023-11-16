#pragma once

#include <iostream>

class ASpell;

class ATarget
{
	std::string _type;

	public:
		ATarget();
		ATarget(std::string const &type);
		ATarget(const ATarget &src);
		virtual ~ATarget();

		ATarget	&operator=(const ATarget &src);
		std::string const	&getType(const ATarget &src);
		void	getHitBySpell(const ASpell &spellRef) const;
		virtual ATarget	*clone() const = 0;
};

#include "ASpell.hpp"
