/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:42:08 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 16:47:43 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;

		while (av[1][i])
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'm') || (av[1][i] >= 'A' && av[1][i] <= 'Z'))
				ft_putchar(av[1][i] + 13);
			else if ((av[1][i] >= 'N' && av[1][i] <= 'Z') || (av[1][i] >= 'n' && av[1][i] <= 'z'))
				ft_putchar(av[1][i] - 13);
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
}