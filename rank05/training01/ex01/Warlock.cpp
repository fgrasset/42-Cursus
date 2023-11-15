#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done !" << std::endl;
}

std::string const	&Warlock::getName() const
{
	return this->_name;
}

std::string const	&Warlock::getTitle() const
{
	return this->_title;
}

void	Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		this->arr.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	Warlock::forgetSpell(std::string spell_name)
{
	std::map<std::string, ASpell *>::iterator	it = this->arr.find(spell_name);
	if (it != this->arr.end())
		delete it->second;
	this->arr.erase(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, ATarget const &target)
{
	ASpell *spell = this->arr[spell_name];
	if (spell)
		spell->launch(target);
}
