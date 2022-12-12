/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:49:01 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 16:56:09 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 4 && av[2][1] == 0 && av[3][1] == 0)
	{
		int	i = 0;

		while (av[1][i])
		{
			if (av[1][i] == av[2][0])
			{
				av[1][i] = av[3][0];
			}
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			ft_putchar(av[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}