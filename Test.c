#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

/* checks if nb is in int scope false if not */
int	ismaxmin(int nb)
{
	if (nb > 2147483647)
		return 0;
	else if (nb < -2147483648)
		return 0;
	else
		return 1;
}

/* returns true if it is a number, false otherwise */
int	isanumber(int nb)
{
	while (nb != 0)
	{
		if ((nb % 10) < -9 || (nb % 10) > 9)
		{
			printf("%d\n", nb % 10);
			return (0);
		}
		nb /= 10;
		printf("%d\n", nb);
	}
	return (1);
}

int	main(int ac, char **av)
{
	(void) ac;

	printf("%d\n", atoi(av[1]));
	if (isanumber(atoi(av[1])))
		printf("%s\n", "true");
	else
		printf("%s\n", "false");
}
