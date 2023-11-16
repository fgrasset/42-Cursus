#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::ATarget(std::string const &type) : _type(type)
{

}

ATarget::ATarget(const ATarget &src)
{
	*this = src;
}

ATarget::~ATarget()
{

}

ATarget	&ATarget::operator=(const ATarget &src)
{
	this->_type = src._type;
	return *this;
}

std::string const	&ATarget::getType(const ATarget &src)
{
	return this->_type;
}

void	ATarget::getHitBySpell(const ASpell &spellRef) const
{
	std::cout << this->_type << " has been " << spellRef.getEffects() << "!" << std::endl;
}
