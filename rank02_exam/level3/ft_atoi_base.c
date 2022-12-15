/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:39:14 by fabien            #+#    #+#             */
/*   Updated: 2022/12/15 13:04:25 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isspace(char c)
{
	if (c == ' ' || c == "/t")
		return 1;
	return 0;
}

int	ischar(char c)
{
	if (c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F')
		return 1;
	else if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int	return_hex(char c, int base)
{
	int	nb = c + '0';

	write(1, &"0123456789abcdef"[c % base])
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	sgn = 1;
	int	res = 0;

	while (isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sgn = -1;
		i++;
	}
	while (ischar(str[i]))
	{
		res = (res * 10) + (return_hex(str[i], str_base));
		i++;
	}
}