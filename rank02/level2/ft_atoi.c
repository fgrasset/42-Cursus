/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:23:51 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 17:37:32 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isachar(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	sgn = 1;
	int	atoi = 0;

	while (str[i])
	{
		if (str[i] == '+' || str[i] == ' ')
			i++;
		if (str[i] == '-')
			sgn = -1;
		if (isachar(str[i]))
		{
			while (str[i])
			{
				atoi = (atoi * 10) + (str[i] + '0');
			}
		}
	}
}
