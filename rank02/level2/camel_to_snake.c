/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:05:45 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 17:10:36 by fgrasset         ###   ########.fr       */
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
			if (ag[1][i] >= 'A' && ag[1][i] <= 'Z')
			{
				write(1, "_", 1);
				ft_putchar(ag[1][i] + 32);
			}
			else
			{
				write(1, &ag[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

