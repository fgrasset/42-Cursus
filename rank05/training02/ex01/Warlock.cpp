#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell *>::iterator	it_begin = this->arr.begin();
	std::map<std::string, ASpell *>::iterator	it_end = this->arr.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->arr.clear();
}

std::string const	&Warlock::getName() const
{
	return this->name;
}

std::string const &Warlock::getTitle() const
{
	return this->title;
}

void	Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spellPtr)
{
	if (spellPtr)
		this->arr.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));
}

void	Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator	it = this->arr.find(spellName);
	if (it != this->arr.end())
		delete it->second;
	this->arr.erase(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget &target)
{
	ASpell	*spel = this->arr[spellName];
	if (spel)
		spel->launch(target);
}
