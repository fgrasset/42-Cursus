#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <stdlib.h>

class Base
{
	public:
		Base();
		virtual ~Base();

		static Base	*generate();
		void		identify(Base *p);
		void		identify(Base &p);
};

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#endif
