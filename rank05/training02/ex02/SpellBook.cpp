#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator	it_begin = this->arr_spell.begin();
	std::map<std::string, ASpell *>::iterator	it_end = this->arr_spell.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
		this->arr_spell.clear();
}

void	SpellBook::learnSpell(ASpell *spellPtr)
{
	if (spellPtr)
		this->arr_spell.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));
}

void	SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator	it = this->arr_spell.find(spellName);
	if (it != this->arr_spell.end())
		delete it->second;
	this->arr_spell.erase(spellName);
}

ASpell	*SpellBook::createSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator	it = this->arr_spell.find(spellName);
	if (it != this->arr_spell.end())
		return this->arr_spell[spellName];
	return NULL;
}
