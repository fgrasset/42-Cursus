#ifndef BASE_HPP
# define BASE_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

class A;
class B;
class C;

class Base
{
	public:
		Base();
		virtual ~Base();

		static Base	*generate();
		void		identify(Base *p);
		void		identify(Base &p);
};

#endif
