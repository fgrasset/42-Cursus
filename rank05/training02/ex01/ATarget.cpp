#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::ATarget(std::string const &type) : type(type)
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
	this->type = src.type;
	return *this;
}

std::string const	&ATarget::getType() const
{
	return this->type;
}

void	ATarget::getHitBySpell(const ASpell *spell) const
{
	std::cout << this->type << " has been " << spell->getEffects() << "!" << std::endl;
}
