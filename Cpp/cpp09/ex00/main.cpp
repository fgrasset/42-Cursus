#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Please provide an input file" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange	btc;
		btc.processInput(av[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
