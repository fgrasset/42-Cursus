#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << "Debug :" << std::endl;
	harl.complain("DEBUG");

	std::cout << "Info :" << std::endl;
	harl.complain("INFO");

	std::cout << "Warning :" << std::endl;
	harl.complain("WARNING");

	std::cout << "ERROR :" << std::endl;
	harl.complain("ERROR");

	std::cout << "Inexistant level :" << std::endl;
	harl.complain("?");
}
