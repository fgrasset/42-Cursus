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

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		this->arr_spell.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator	it = this->arr_spell.find(spell);
	if (it != this->arr_spell.end())
		delete it->second;
	this->arr_spell.erase(spell);
}

ASpell	*SpellBook::createSpell(std::string const &spell)
{
	std::map<std::string, ASpell*>::iterator	it = this->arr_spell.find(spell);
	if (it != this->arr_spell.end())
		return (this->arr_spell[spell]);
	return NULL;
}
