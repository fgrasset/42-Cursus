/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:44:19 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 10:00:54 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	sgn = 1;
	int	i = 0;
	int	res = 0;

	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sgn = -1;
		i++;
	}
	else if (str[i] == '+')
			i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}

int main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_atoi(av[1]));
}