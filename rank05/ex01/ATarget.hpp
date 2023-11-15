#pragma once

#include <iostream>

class ASpell;

class ATarget
{
	std::string	_type;

	public:
		ATarget();
		ATarget(std::string const &type);
		virtual ~ATarget();
		ATarget(const ATarget &src);

		ATarget		&operator=(const ATarget &src);
		std::string const	&ATarget::getType() const;

		void	getHitBySpell(ASpell const &spell) const;

		virtual ATarget *clone() = 0;
};

#include "ASpell.hpp"
