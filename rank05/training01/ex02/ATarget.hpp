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
		std::string const	&getType() const;
		virtual ATarget	*clone() const = 0;

		void	getHitBySpell(const ASpell &spell) const;
};

#include "ASpell.hpp"
