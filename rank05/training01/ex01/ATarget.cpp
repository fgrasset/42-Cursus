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

std::string const	&ATarget::getType() const
{
	return this->_type;
}

void	ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << "hit spell" << std::endl;
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}
