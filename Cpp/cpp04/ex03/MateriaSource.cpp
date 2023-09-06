#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	if (&src == this)
		return *this;
	return *this;
}

void			MateriaSource::learnMateria(AMateria* materia)
{
	_stock[_index] = materia;
	if (_index == 3)
		_index = 0;
	else
		_index++;
}

AMateria*		MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_stock[i]->getType() == type)
		{
			AMateria* materia = _stock[i]->clone();
			return (materia);
		}
	}
	return (0);
}

