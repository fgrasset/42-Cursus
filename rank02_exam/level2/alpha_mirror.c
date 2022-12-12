/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:04:25 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 17:10:18 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	mirror(char c)
{
	char	*fhalf = "mlkjihgfedcba";
	char	*shalf = "nopqrstuvwxyz";
	int		i = 0;

	while (fhalf[i] != c)
		i++;
	return (shalf[i]);
}



int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;

		while (av[1][i])
		{

		}
	}
}