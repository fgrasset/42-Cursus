/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:03 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 16:41:18 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	return i;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	size = ft_strlen(av[1]);

		while (size > -1)
		{
			write(1, &av[1][size], 1);
			size--;
		}
	}
	write(1, "\n", 1);
}