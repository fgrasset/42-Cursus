#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main()
{
	srand(time(NULL));

	Base *base = new Base();

	Base *x = base->generate();
	Base *y = base->generate();
	Base *z = base->generate();

	base->identify(x);
	base->identify(y);
	base->identify(z);

	Base &rx = *x;
	Base &ry = *y;
	Base &rz = *z;

	base->identify(rx);
	base->identify(ry);
	base->identify(rz);

	Base *nullPtr = nullptr;
	base->identify(nullPtr);

	delete base;

	return 0;
}
