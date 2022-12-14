/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:22:16 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 11:28:51 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int x = atoi(av[1]);
		int	y = atoi(av[2]);
		int	n = 0;

		if (x >= y)
			n = x;
		else	
			n = y;
		
		while (n > 0)
		{
			if ((x % n == 0) && (y % n == 0))
			{
				printf("%d", n);
				break;
			}
			n--;
		}
	}
	printf("\n");
}