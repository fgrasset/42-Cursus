/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:50:50 by fabien            #+#    #+#             */
/*   Updated: 2023/03/08 19:57:38 by fabien           ###   ########.fr       */
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
			if (ag[1][i] == '_')
			{
				ft_putchar(ag[1][i+1] - 32);
				i++;
			}
			else
				write(1, &ag[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
