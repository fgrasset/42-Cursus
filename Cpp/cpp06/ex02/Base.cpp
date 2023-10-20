#include "Base.hpp"

Base::Base()
{

}

Base::~Base()
{

}

Base	*Base::generate()
{
	srand(time(NULL));
	int	random = rand() % 3;

}

void	Base::identify(Base *p)
{
	if (A *a = dynamic_cast<A*>(p))
		std::cout << "This is a pointer of class A" << std::endl;
	else if (B *b = dynamic_cast<B*>(p))
		std::cout << "This is a pointer of class B" << std::endl;
	else if (C *c = dynamic_cast<C*>(p))
		std::cout << "This is a pointer of class C" << std::endl;
	else
		std::cout << "This is not a known class" << std::endl;
}

void	Base::identify(Base &p)
{
	if (A &a = dynamic_cast<A&>(p))
		std::cout << "This is a pointer of class A" << std::endl;
	else if (B &b = dynamic_cast<B&>(p))
		std::cout << "This is a pointer of class B" << std::endl;
	else if (C &c = dynamic_cast<C&>(p))
		std::cout << "This is a pointer of class C" << std::endl;
	else
		std::cout << "This is not a known class" << std::endl;
}
