/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:54:49 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 16:59:33 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **ag)
{
	if (ac == 2)
	{
		int	i = 0;

		while (ag[1][i])
		{
			if (ag[1][i] >= 'A' && ag[1][i] <= 'M')
				ft_putchar(ag[1][i] + 13);
			else if (ag[1][i] >= 'N' && ag[1][i] <= 'Z')
				ft_putchar(ag[1][i] - 13);
			else if (ag[1][i] >= 'a' && ag[1][i] <= 'm')
				ft_putchar(ag[1][i] + 13);
			else if (ag[1][i] >= 'n' && ag[1][i] <= 'z')
				ft_putchar(ag[1][i] - 13);
			else
				ft_putchar(ag[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
