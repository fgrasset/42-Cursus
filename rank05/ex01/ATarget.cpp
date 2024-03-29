#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::ATarget(std::string const &type): _type(type)
{

}

ATarget::~ATarget()
{

}

ATarget::ATarget(const ATarget &src)
{
	*this = src;
}

ATarget	&ATarget::operator=(const ATarget &src)
{
	this->_type = src._type;
	return (*this);
}

std::string const	&ATarget::getType() const
{
	return (this->_type);
}

void		ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}
