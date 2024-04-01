#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate()
{
	std::srand(std::time(nullptr));
	int	random = rand() % 3;

	switch (random) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return NULL;
	}
}

void	identify(Base *p)
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

void	identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "This is a reference of class A" << std::endl;
		return ;
	} catch (std::bad_cast& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "This is a reference of class B" << std::endl;
		return ;
	} catch (std::bad_cast& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "This is a reference of class C" << std::endl;
		return ;
	} catch (std::bad_cast& e) {}
}


int	main()
{
	Base *testBase;
	testBase = generate();
	identify(testBase);
	identify(*testBase);
	delete testBase;

	return 0;
}
