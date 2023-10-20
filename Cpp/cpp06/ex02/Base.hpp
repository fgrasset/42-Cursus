#ifndef BASE_HPP
# define BASE_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

class Base
{
	public:
		Base();
		~Base();

		Base	*generate();
		void	identify(Base *p);
		void	identify(Base &p);
};

#endif
