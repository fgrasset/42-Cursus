#include <iostream>

int	main(int ac, char **av)
{
	int	i = 0;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[++i])
		{
			j = -1;
			while (av[i][++j])
				std::cout << (char) std::toupper(av[i][j]);
		}
		std::cout << std::endl;
	}
}
