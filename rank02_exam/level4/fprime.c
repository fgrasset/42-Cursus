/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:54:04 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 14:05:55 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	n = atoi(av[1]);
		int	i = 0;

		if (n == 1)
			printf("1");
		while(n != 1)
		{
			i = 2;
			while(n % i != 0)
				i++;
			printf("%d", i);
			n /= i;
			if (n != 1)
				printf("*");
		}
	}
	printf("\n");
}