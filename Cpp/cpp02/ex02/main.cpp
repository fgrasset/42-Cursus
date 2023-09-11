#include "Fixed.hpp"

int	main()
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << "The max is: " << Fixed::max(a, b) << std::endl;
	std::cout << "The min is: " << Fixed::min(a, b) << std::endl;

	return 0;
}
