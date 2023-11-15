#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects)
{

}

ASpell::ASpell(const ASpell &src)
{
	*this = src;
}

ASpell::~ASpell()
{

}

ASpell	&ASpell::operator=(const ASpell &src)
{
	this->name = src.name;
	this->effects = src.effects;
	return *this;
}

std::string const	&ASpell::getName() const
{
	return this->name;
}

std::string const	&ASpell::getEffects() const
{
	return this->effects;
}

void	ASpell::launch(const ATarget &target_ref) const
{
	target_ref.getHitBySpell(this);
}
