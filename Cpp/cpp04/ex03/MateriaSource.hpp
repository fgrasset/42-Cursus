#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	AMateria	*_stock[4];
	int			_index;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &src);
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif
