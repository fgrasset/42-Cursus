/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:02:11 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/12 09:40:09 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_positive_number(char *str);

/* check that the given infos are correct, returns true if it is */
int	infos_check(char **infos, int nb_args)
{
	/*
	check that there is enough/not too much infos,
	and that they are correctly formatted (eg. numbers only)
	*/
	int	i;

	i = 0;
	if (nb_args < 5 || nb_args > 6)
		return (0);
	while (infos[++i])
	{
		if (!is_positive_number(infos[i]))
			return (0);
	}
	return (1);
}

/* returns true if the string is only positive numbers */
int	is_positive_number(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		return (0);
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
