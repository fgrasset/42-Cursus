#pragma once

#include "ASpell.hpp"alignas

class Fwoosh: public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();

		virtual ASpell *clone() const;
};
