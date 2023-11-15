#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
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
		book.learnSpell(spellPtr);
}

void	Warlock::forgetSpell(std::string spellName)
{
	book.forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	ASpell	*spel = book.createSpell(spellName);
	std::cout << "test" << std::endl;
	if (spel)
		spel->launch(target);
}
