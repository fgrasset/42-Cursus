/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:57:05 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/18 13:58:24 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sgn;
	int	atoi;

	i = 0;
	sgn = 1;
	atoi = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sgn = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isadigit(str[i]))
	{
		atoi = (atoi * 10) + (str[i] - '0');
		i++;
	}
	return (atoi * sgn);
}
