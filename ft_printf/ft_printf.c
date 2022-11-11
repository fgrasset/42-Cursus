/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:32:55 by fabien            #+#    #+#             */
/*   Updated: 2022/11/11 17:10:10 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print	*ft_initialise_struct(print *tab)
// {
// 	tab->len = 0;
// 	tab->prc = 0;
// 	tab->sgn = 0;
// 	tab->s = s(string);
// 	return (tab);
// }

int	check_flag(va_list args, char flag)
{
	if (flag == 'c')
		return (printf_c(va_arg(args, int)));
	else if (flag == 's')
		return (printf_s(va_arg(args, char *)));
	else if (flag == '%')
		return (printf_prc());
	else if (flag == 'd' || flag == 'i')
		return (printf_d(va_arg(args, int)));
	else if (flag == 'u')
		return (printf_u(va_arg(args, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *string, ...)
{
	// print	*tab;
	int		i;
	int		res;

	va_list args;
	va_start(args, string);
	// ft_initialise_struct(tab);
	i = -1;
	res = 0;
	while (string[++i])
	{
		if (string[i] == '%')
		{
			res += check_flag(args, string[i + 1]);
			i++;
		}
		else
			res += write(1, &string[i], 1);
	}
	va_end(args);
	return (res);
}