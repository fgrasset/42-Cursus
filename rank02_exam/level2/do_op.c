/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:25:00 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 09:37:37 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int	x = atoi(av[1]);
		int	y = atoi(av[3]);

		if (av[2][0] == '+')
			printf("%d\n", x + y);
		else if (av[2][0] == '-')
			printf("%d\n", x - y);
		else if (av[2][0] == '*')
			printf("%d\n", x * y);
		else if (av[2][0] == '/')
			printf("%d\n", x / y);
		else if (av[2][0] == '%')
			printf("%d\n", x % y);
	}
	else
		write(1, "\n", 1);
}