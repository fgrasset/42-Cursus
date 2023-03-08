/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:39:41 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 16:48:58 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **ag)
{
	int	i = 0;
	int	tmp = 0;

	if (ac == 2)
	{
		while (ag[1][i])
		{
			tmp = 1;
			if (ag[1][i] >= 'A' && ag[1][i] <= 'Z')
				tmp = (ag[1][i]) - 64;
			if (ag[1][i] >= 'a' && ag[1][i] <= 'z')
				tmp = (ag[1][i]) - 96;
			while (tmp > 0)
			{
				putchar(ag[1][i]);
				tmp--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
