#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator	it_begin = this->arr_target.begin();
	std::map<std::string, ATarget *>::iterator	it_end = this->arr_target.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->arr_target.clear();
}

void	 TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		this->arr_target.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const &target)
{
	this->arr_target.erase(target);
}

ATarget	*TargetGenerator::createTarget(std::string const &target_ref)
{
	std::map<std::string, ATarget *>::iterator	it = this->arr_target.find(target_ref);
	if (it != this->arr_target.end())
		return this->arr_target[target_ref];
	return NULL;
}
