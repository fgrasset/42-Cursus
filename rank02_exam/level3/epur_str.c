/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:13:00 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 10:25:30 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isaspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == ' ')
		return 1;
	return 0;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = -1;
		
		while (av[1][++i])
		{
			while (isaspace(av[1][i]))
				i++;
			while (!isaspace(av[1][i]))
			{
				write(1, &av[1][i], 1);
				i++;
			}
			write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}