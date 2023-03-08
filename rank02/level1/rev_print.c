/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:49:35 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 16:54:19 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;

	return (i);
}

int	main(int ac, char **ag)
{
	if (ac == 2)
	{
		int size = ft_strlen(ag[1]) - 1;
		while (size >= 0)
		{
			write(1, &ag[1][size],1 );
			size--;
		}
	}
	write(1, "\n", 1);
}
