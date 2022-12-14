/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:14:10 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 11:20:42 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	i = 2;

	while(1)
	{
		if ((a % i == 0) && (b % i == 0))
			return i;
		i++;
	}
}

int	main(int ac, char **av)
{
	printf("%d\n", lcm(atoi(av[1]), atoi(av[2])));
}